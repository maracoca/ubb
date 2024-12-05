//
// Created by mara on 5/20/2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_admin.h" resolved

#include "admin.h"
#include "Movie.h"
#include "Exceptions.h"
#include <QMessageBox>
#include <QListWidget>


AdminGUI::AdminGUI(Service &_service, QWidget *parent) : QWidget(parent), service(_service) {
    this->mainAdminLayout = new QVBoxLayout(this);

    this->adminTitle = new QLabel("Welcome to Admin Mode!", this);
    this->adminTitle->setAlignment(Qt::AlignHCenter);
    this->mainAdminLayout->addWidget(this->adminTitle);


    this->moviesInfoLayout = new QHBoxLayout;
    this->moviesInfo = new QVBoxLayout;

    this->createTitleLayout();
    this->createGenreLayout();
    this->createTrailerLayout();
    this->createYearLayout();
    this->createLikesLayout();
    this->createAdminButtons();

    this->moviesInfo->addLayout(this->titleLayout);
    this->moviesInfo->addLayout(this->genreLayout);
    this->moviesInfo->addLayout(this->trailerLayout);
    this->moviesInfo->addLayout(this->yearLayout);
    this->moviesInfo->addLayout(this->likesLayout);

    this->moviesInfoLayout->addLayout(this->moviesInfo);
    this->mainAdminLayout->addLayout(this->moviesInfoLayout);

    this->mainAdminLayout->addLayout(this->buttonsLayout);

    this->setFixedSize(1200, 270);

    this->createMoviesListWidget();
}

void  AdminGUI::createAdminButtons() {

    this->buttonsLayout = new QHBoxLayout;
    this->addButton = new QPushButton("ADD", this);
    this->deleteButton = new QPushButton("DELETE", this);
    this->updateButton = new QPushButton("UPDATE", this);
    connect(this->addButton, &QPushButton::clicked, this, &AdminGUI::addButtonClicked);
    connect(this->deleteButton, &QPushButton::clicked, this, &AdminGUI::deleteButtonClicked);
    connect(this->updateButton, &QPushButton::clicked, this, &AdminGUI::updateButtonClicked);
    this->buttonsLayout->addWidget(this->addButton);
    this->buttonsLayout->addWidget(this->deleteButton);
    this->buttonsLayout->addWidget(this->updateButton);
}


void AdminGUI::closeButtonClicked() {
    emit CloseAdminWindow();
}

void AdminGUI::createTitleLayout() {
    this->titleLayout=new QHBoxLayout;
    this->titleLabel=new QLabel("Enter title");
    this->titleInput=new QLineEdit(this);
    this->titleLayout->addWidget(this->titleLabel);
    this->titleLayout->addWidget(this->titleInput);
}

void AdminGUI::createGenreLayout() {
    this->genreLayout=new QHBoxLayout;
    this->genreLabel=new QLabel("Enter genre");
    this->genreInput=new QLineEdit(this);
    this->genreLayout->addWidget(this->genreLabel);
    this->genreLayout->addWidget(this->genreInput);


}

void AdminGUI::createTrailerLayout() {
    this->trailerLayout=new QHBoxLayout;
    this->trailerLabel=new QLabel("Enter trailer");
    this->trailerInput=new QLineEdit(this);
    this->trailerLayout->addWidget(this->trailerLabel);
    this->trailerLayout->addWidget(this->trailerInput);


}
void AdminGUI::createYearLayout() {
    this->yearLayout=new QHBoxLayout;
    this->yearLabel=new QLabel("Enter year");
    this->yearInput=new QLineEdit(this);
    this->yearLayout->addWidget(this->yearLabel);
    this->yearLayout->addWidget(this->yearInput);


}
void AdminGUI::createLikesLayout()  {
    this->likesLayout=new QHBoxLayout;
    this->likesLabel=new QLabel("Enter likes");
    this->likesInput=new QLineEdit(this);
    this->likesLayout->addWidget(this->likesLabel);
    this->likesLayout->addWidget(this->likesInput);


}

void AdminGUI::createTableWidget() {
    this->moviesTable=new QTableWidget;
    QStringList header={"Title", "Genre" ,"Trailer", "Year Release" , "Nr likes"};
    this->moviesTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->moviesTable->setColumnCount(5);
    this->moviesTable->setColumnWidth(0, 80);
    this->moviesTable->setColumnWidth(1, 60);
    this->moviesTable->setColumnWidth(2, 60);
    this->moviesTable->setColumnWidth(3, 60);
    this->moviesTable->setColumnWidth(4, 300);
    this->moviesTable->setHorizontalHeaderLabels(header);

    std::vector<Movie> movies = this->service.getMoviesService();
    for (auto movie : movies)
    {
        int rowCount = this->moviesTable->rowCount();
        this->moviesTable->insertRow(rowCount);
        this->moviesTable->setItem(rowCount, 0, new QTableWidgetItem(QString::fromStdString(movie.getTitle())));
        this->moviesTable->setItem(rowCount, 1, new QTableWidgetItem(QString::fromStdString(movie.getGenre())));
        this->moviesTable->setItem(rowCount, 2, new QTableWidgetItem(QString::number(movie.getYear())));
        this->moviesTable->setItem(rowCount, 3, new QTableWidgetItem(QString::number(movie.getLikes())));
        this->moviesTable->setItem(rowCount, 4, new QTableWidgetItem(QString::fromStdString(movie.getTrailer())));
    }


}


void AdminGUI::addButtonClicked() {
    try {
        Movie movie = this->extractMovieInfo();
        if (!movie.getTitle().empty()) {
            bool added = this->service.addService(movie);
            if (added) {
                this->reloadMoviesTable();
                QMessageBox::information(this, "Success", "Movie successfully added!");
                this->titleInput->setText("");
                this->genreInput->setText("");
                this->trailerInput->setText("");
                this->yearInput->setText("");
                this->likesInput->setText("");
            } else {
                QMessageBox::warning(this, "Error", "Movie already exists in the repository!");
            }
        } else {
            QMessageBox::warning(this, "Error", "Invalid movie data. Please correct the input.");
        }
    } catch (RepositoryException &ex) {
        QMessageBox::warning(this, "Error", ex.what());
    } catch (const std::exception &ex) {
        QMessageBox::critical(this, "Error", ex.what());
    } catch (MovieExceptions &ex) {
        std::vector<std::invalid_argument> errors = ex.returnErrors();
        QString errorMessage = "Invalid movie data:";
        for (const auto &error: errors) {
            errorMessage += "\n- " + QString::fromStdString(error.what());
        }
        QMessageBox::warning(this, "Error", errorMessage);
    }
}



void AdminGUI::deleteButtonClicked() {
        try {
            Movie movie = this->extractMovieInfo();
            if (!movie.getTitle().empty()) {
                bool removed = this->service.removeService(movie);
                if (removed) {
//                    this->titleInput->setText("");
//                    this->genreInput->setText("");
//                    this->trailerInput->setText("");
//                    this->yearInput->setText("");
//                    this->likesInput->setText("");
                    this->reloadMoviesTable();
                    QMessageBox::information(this, "Success", "Movie successfully removed!");
                    this->titleInput->setText("");
                    this->genreInput->setText("");
                    this->trailerInput->setText("");
                    this->yearInput->setText("");
                    this->likesInput->setText("");
                } else {
                    QMessageBox::warning(this, "Error", "Movie does not exist in the repository!");
                }
            } else {
                QMessageBox::warning(this, "Error", "Invalid movie data. Please correct the input.");
            }
        } catch (const std::exception &ex) {
            QMessageBox::critical(this, "Error", ex.what());
        }
    }


void AdminGUI::updateButtonClicked() {
    QListWidgetItem* selectedItem = this->moviesListWidget->currentItem();
    if (!selectedItem) {
        QMessageBox::warning(this, "Error", "No movie selected. Please select a movie to update.");
        return;
    }

    QString selectedMovieInfo = selectedItem->text();
    QStringList movieDetails = selectedMovieInfo.split(" | ");
    if (movieDetails.size() < 5) {
        QMessageBox::warning(this, "Error", "Selected movie information is incomplete.");
        return;
    }
    std::string trailer = movieDetails[2].toStdString();

    try {
        Movie modifiedMovie = this->extractMovieInfo();

        if (modifiedMovie.getTitle().empty() || modifiedMovie.getGenre().empty() ||
            modifiedMovie.getTrailer().empty() || modifiedMovie.getYear() == 0 ||
            modifiedMovie.getLikes() == 0) {
            QMessageBox::warning(this, "Error", "Invalid movie data. Please correct the input.");
            return;
        }

        Movie oldMovie = this->service.findMovieByTrailer(trailer);
        int pos = this->service.findMoviePosition(oldMovie);
        this->service.updateMovieService(pos, modifiedMovie);

        this->reloadMoviesTable();

        QMessageBox::information(this, "Success", "Movie successfully updated!");

        this->titleInput->setText("");
        this->genreInput->setText("");
        this->trailerInput->setText("");
        this->yearInput->setText("");
        this->likesInput->setText("");
    } catch (const std::exception &ex) {
        QMessageBox::critical(this, "Error", ex.what());
    }
}



Movie AdminGUI::extractMovieInfo()  {
    QString title = this->titleInput->text();
    QString genre = this->genreInput->text();
    QString trailer = this->trailerInput->text();
    QString year = this->yearInput->text();
    QString likes = this->likesInput->text();

    bool yearConversionOk;
    int yearInt = year.toInt(&yearConversionOk);
    if (!yearConversionOk) {
        QMessageBox::warning(this, "Error", "Invalid year input. Please enter a valid integer.");
        return Movie();
    }

    bool likesConversionOk;
    int likesInt = likes.toInt(&likesConversionOk);
    if (!likesConversionOk) {
        QMessageBox::warning(this, "Error", "Invalid likes input. Please enter a valid integer.");
        return Movie();
    }

    Movie movie{title.toStdString(), genre.toStdString(), yearInt, likesInt, trailer.toStdString()};
    return movie;
}

void AdminGUI::reloadMoviesTable() {
//    this->moviesTable->setRowCount(0);
//    std::vector<Movie> movies = this->service.getMoviesService();
//    for (auto movie: movies) {
//        int rowCount = this->moviesTable->rowCount();
//        this->moviesTable->insertRow(rowCount);
//        this->moviesTable->setItem(rowCount, 0, new QTableWidgetItem(QString::fromStdString(movie.getTitle())));
//        this->moviesTable->setItem(rowCount, 1, new QTableWidgetItem(QString::fromStdString(movie.getGenre())));
//        this->moviesTable->setItem(rowCount, 2, new QTableWidgetItem(QString::number(movie.getYear())));
//        this->moviesTable->setItem(rowCount, 3, new QTableWidgetItem(QString::number(movie.getLikes())));
//        this->moviesTable->setItem(rowCount, 4, new QTableWidgetItem(QString::fromStdString(movie.getTrailer())));
//    }

        this->moviesListWidget->clear();

        std::vector<Movie> movies = this->service.getMoviesService();

        for (const auto &movie : movies) {
            QString movieInfo = QString::fromStdString(movie.getTitle()) + " | " +
                                QString::fromStdString(movie.getGenre()) + " | " +
                                QString::fromStdString(movie.getTrailer()) + " | " +
                                QString::number(movie.getYear()) + " | " +
                                QString::number(movie.getLikes());

            this->moviesListWidget->addItem(movieInfo);
        }
    }


void AdminGUI::createMoviesListWidget() {
    this->moviesListWidget = new QListWidget(this);
    this->mainAdminLayout->addWidget(this->moviesListWidget);

    std::vector<Movie> movies = this->service.getMoviesService();
    for (const auto& movie : movies) {
        QString movieInfo = QString::fromStdString(movie.getTitle()) + " | " +
                            QString::fromStdString(movie.getGenre()) + " | " +
                            QString::fromStdString(movie.getTrailer()) + " | " +
                            QString::number(movie.getYear()) + " | " +
                            QString::number(movie.getLikes()) ;
        this->moviesListWidget->addItem(movieInfo);
    }

    connect(this->moviesListWidget, &QListWidget::itemClicked, this, &AdminGUI::displaySelectedMovie);
}

void AdminGUI::displaySelectedMovie() {
    QListWidgetItem* selectedItem = this->moviesListWidget->currentItem();
    if (selectedItem) {
        QString selectedMovieInfo = selectedItem->text();
        QMessageBox::information(this, "Selected Movie", selectedMovieInfo);
    }
}
