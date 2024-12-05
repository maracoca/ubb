//
// Created by mara on 5/20/2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_user.h" resolved

#include <QDesktopServices>
#include "user.h"
#include "HTMLwl.h"
#include "csvWL.h"


UserGUI::UserGUI(Service& _service, QWidget *parent)
        : service(_service), QWidget(parent) {

    QVBoxLayout* movieLayout = new QVBoxLayout(this);

    QLabel* userModeTitle = new QLabel("User mode!", this);
    movieLayout->addWidget(userModeTitle, 0, Qt::AlignCenter);

    QHBoxLayout* comboBoxLayout1 = this->createComboBoxLayout();
    movieLayout->addLayout(comboBoxLayout1);

    QHBoxLayout* buttons = this->createUserButtons();
    movieLayout->addLayout(buttons);

    QHBoxLayout* genreInputLayout = this->createGenreInputLayout();
    movieLayout->addLayout(genreInputLayout);

    QHBoxLayout* movieStackedWidget = this->createStackedWidgetLayout();
    movieLayout->addLayout(movieStackedWidget);

    QHBoxLayout* browsingButtons = this->createBrowsingButtons();
    movieLayout->addLayout(browsingButtons);

    QVBoxLayout* watchlistLayout = this->createWatchlistLayout();
    movieLayout->addLayout(watchlistLayout);

    QHBoxLayout* openFileButtonLayout = this->createOpenFileButtonLayout();
    movieLayout->addLayout(openFileButtonLayout);

    QPushButton* closeButton = new QPushButton("EXIT");
    connect(closeButton, &QPushButton::clicked, this, &UserGUI::closeButtonClicked);
    movieLayout->addWidget(closeButton);

    this->setLayout(movieLayout);
}


QVBoxLayout* UserGUI::createWatchlistLayout() {
    QVBoxLayout* watchlistLayout = new QVBoxLayout;

    watchlistWidget = new QListWidget(this);
    watchlistLayout->addWidget(watchlistWidget);

    QPushButton* deleteButton = new QPushButton("Delete Selected Movie", this);
    connect(deleteButton, &QPushButton::clicked, this, &UserGUI::deleteSelectedMovie);
    watchlistLayout->addWidget(deleteButton);

    return watchlistLayout;
}

QHBoxLayout* UserGUI::createComboBoxLayout() {
    auto* comboBoxLayout = new QHBoxLayout;
    auto* label = new QLabel("Format of Watchlist Export", this);
    watchFileType = new QComboBox(this);
    watchFileType->addItem("Select Format");
    watchFileType->addItem("CSV");
    watchFileType->addItem("HTML");
    comboBoxLayout->addWidget(label);
    comboBoxLayout->addWidget(watchFileType);

    connect(watchFileType, &QComboBox::currentTextChanged, this, &UserGUI::watchlistFileTypeHandler);

    return comboBoxLayout;
}

QHBoxLayout* UserGUI::createUserButtons() {
    QHBoxLayout* layout = new QHBoxLayout;
    QLabel* inputSizeLabel = new QLabel("Enter genre:");
    genreInput = new QLineEdit(this);
    layout->addWidget(inputSizeLabel);
    layout->addWidget(genreInput);
    return layout;
}

QHBoxLayout* UserGUI::createGenreInputLayout() {
    QHBoxLayout* layout = new QHBoxLayout;

    QPushButton* okButton = new QPushButton("OK");
    connect(okButton, &QPushButton::clicked, this, &UserGUI::okButtonClicked);
    layout->addWidget(okButton);

    return layout;
}

QHBoxLayout* UserGUI::createStackedWidgetLayout() {
    QHBoxLayout* layout = new QHBoxLayout;
    this->stackedWidget = new QStackedWidget;
    QWidget* firstPage = new QWidget;
    this->stackedWidget->addWidget(firstPage);
    this->stackedWidget->setCurrentIndex(0);
    layout->addWidget(this->stackedWidget);
    return layout;
}

QHBoxLayout* UserGUI::createBrowsingButtons() {
    QHBoxLayout* layout = new QHBoxLayout;
    QPushButton* nextButton = new QPushButton("Next");
    connect(nextButton, &QPushButton::clicked, this, &UserGUI::nextButtonClicked);
    QPushButton* addToWatchlistButton = new QPushButton("Add to watch list");
    connect(addToWatchlistButton, &QPushButton::clicked, this, &UserGUI::addToWatchListButtonClicked);
    layout->addWidget(nextButton);
    layout->addWidget(addToWatchlistButton);
    return layout;
}

QHBoxLayout* UserGUI::createOpenFileButtonLayout() {
    QHBoxLayout* buttonLayout = new QHBoxLayout;
    QPushButton* openFileButton = new QPushButton("Open Watchlist File", this);
    connect(openFileButton, &QPushButton::clicked, this, &UserGUI::openWatchlistFile);
    buttonLayout->addWidget(openFileButton);
    return buttonLayout;
}

void UserGUI::populateWatchlist() {
    watchlistWidget->clear();
    std::vector<Movie> movies = service.getMoviesTheUserLikes();
    for (const Movie& movie : movies) {
        watchlistWidget->addItem(QString::fromStdString(movie.getTitle()));
    }
}

void UserGUI::deleteSelectedMovie() {
    QListWidgetItem* selectedItem = watchlistWidget->currentItem();
    if (!selectedItem) {
        QMessageBox::warning(this, "Delete Movie", "No movie selected!");
        return;
    }

    int selectedIndex = watchlistWidget->row(selectedItem);

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Like Movie", "Do you want to like this movie before deleting?",
                                  QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);

    if (reply == QMessageBox::Cancel) {
        return;
    }

    if (reply == QMessageBox::Yes) {
        service.increaseLikesOfMovie(selectedIndex);
    }

    service.removeWatchList(selectedIndex);
    delete selectedItem;
}

void UserGUI::watchlistFileTypeHandler() {
    if (this->watchFileType->currentText() == "CSV")
        this->service.setTypeOfWatchList(new CSVWatchList{"watchlist.csv"});
    else
        this->service.setTypeOfWatchList(new HTMLWatchList{"watchlist.html"});
}

void UserGUI::closeButtonClicked() {
    emit CloseUserWindow();
}

void UserGUI::okButtonClicked() {
    QString genre = genreInput->text();
    std::string genreStr = genre.toStdString();

    if (genreStr.empty()) {
        movies = service.getMoviesService();
    } else {
        movies = service.getMoviesByGenre(genreStr);
    }

    currentMovieIndex = 0;
    updateMovieDisplay();
}

void UserGUI::nextButtonClicked() {
    if (!movies.empty()) {
        currentMovieIndex = (currentMovieIndex + 1) % movies.size();
        updateMovieDisplay();
    }
}

void UserGUI::addToWatchListButtonClicked() {
    if (movies.empty()) {
        QMessageBox::warning(this, "Error", "No movies to add to the watchlist!");
        return;
    }
    QString selectedFormat = this->watchFileType->currentText();

    if (selectedFormat == "Select Format") {
        QMessageBox::warning(this, "Warning", "Please select a file type for the watchlist export.");
        return;
    }

    if (currentMovieIndex < 0 || currentMovieIndex >= movies.size()) {
        QMessageBox::warning(this, "Error", "Invalid movie index!");
        return;
    }

    try {
        Movie currentMovie = movies[currentMovieIndex];
        service.addMovieToWatchList(currentMovie);
        QMessageBox::information(this, "Watchlist", "Movie added to watchlist!");
        populateWatchlist();
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Error", QString::fromStdString(e.what()));
    } catch (...) {
        QMessageBox::critical(this, "Error", "An unknown error occurred.");
    }
}

void UserGUI::genreInputChanged() {
    QString genre = genreInput->text();
    std::string genreStr = genre.toStdString();

    if (genreStr.empty()) {
        movies = service.getMoviesService();
    } else {
        movies = service.getMoviesByGenre(genreStr);
    }

    currentMovieIndex = 0;
    updateMovieDisplay();
}

void UserGUI::updateMovieDisplay() {
    int noOfWidgets = stackedWidget->count();
    for (int i = noOfWidgets - 1; i > 0; i--) {
        QWidget* removedPage = stackedWidget->widget(i);
        stackedWidget->removeWidget(removedPage);
        delete removedPage;
    }

    if (!movies.empty()) {
        Movie& movie = movies[currentMovieIndex];
        QWidget* newPage = new QWidget;
        QVBoxLayout* pageLayout = new QVBoxLayout;

        QTableWidget* moviesTable = new QTableWidget;
        moviesTable->setColumnCount(5);
        QStringList header = { "Title", "Genre", "Trailer", "Year Release", "Nr likes" };
        moviesTable->setHorizontalHeaderLabels(header);

        int rowCount = moviesTable->rowCount();
        moviesTable->insertRow(rowCount);
        moviesTable->setItem(rowCount, 0, new QTableWidgetItem(QString::fromStdString(movie.getTitle())));
        moviesTable->setItem(rowCount, 1, new QTableWidgetItem(QString::fromStdString(movie.getGenre())));
        moviesTable->setItem(rowCount, 2, new QTableWidgetItem(QString::fromStdString(movie.getTrailer())));
        moviesTable->setItem(rowCount, 3, new QTableWidgetItem(QString::number(movie.getYear())));
        moviesTable->setItem(rowCount, 4, new QTableWidgetItem(QString::number(movie.getLikes())));

        pageLayout->addWidget(moviesTable);
        newPage->setLayout(pageLayout);

        stackedWidget->addWidget(newPage);
        stackedWidget->setCurrentIndex(stackedWidget->count() - 1);

        QString trailerUrl = QString::fromStdString(movie.getTrailer());
        QDesktopServices::openUrl(QUrl(trailerUrl));
    }
}

void UserGUI::openWatchlistFile() {
    QString selectedFormat = this->watchFileType->currentText();

    if (selectedFormat == "Select Format") {
        QMessageBox::warning(this, "Warning", "Please select a file type for the watchlist export.");
        return;
    }
    try {
        service.displayPlaylist();
    } catch (const std::exception& e) {
        QMessageBox::critical(this, "Error", QString::fromStdString(e.what()));
    } catch (...) {
        QMessageBox::critical(this, "Error", "An unknown error occurred.");
    }
}


