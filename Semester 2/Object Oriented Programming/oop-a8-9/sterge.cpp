//
// Created by mara on 5/21/2024.
//

//UserGUI::UserGUI(Service& _service, QWidget *parent) : service(_service), QWidget(parent) {
//    QHBoxLayout* comboBoxLayout = this->createComboBox();
//    QLabel* userModeTitle = new QLabel("Welcome to user mode!", this);
//    QVBoxLayout* trenchCoatsLayout = new QVBoxLayout(this);
//    trenchCoatsLayout->addWidget(userModeTitle, 0, Qt::AlignCenter);
//
//    trenchCoatsLayout->addLayout(comboBoxLayout);
//    QHBoxLayout* buttons = this->createUserButtons();
//    QHBoxLayout* sizeInputLayout = this->createSizeInputLayout();
//    QPushButton* closeButton = new QPushButton("EXIT");
//    connect(closeButton, &QPushButton::clicked, this, &UserGUI::closeButtonClicked);
//    QHBoxLayout* trenchCoatsStackedWidget = this->createStackedWidgetLayout();
//    QHBoxLayout* browsingButtons = this->createBrowsingButtons();
//
//    trenchCoatsLayout->addLayout(buttons);
//    trenchCoatsLayout->addLayout(sizeInputLayout);
//    trenchCoatsLayout->addLayout(trenchCoatsStackedWidget);
//    trenchCoatsLayout->addLayout(browsingButtons);
//    trenchCoatsLayout->addWidget(closeButton);
//
//    this->setLayout(trenchCoatsLayout);
//}
//
//void UserGUI::closeButtonClicked() {
//    emit CloseUserWindow();
//}
//
//QHBoxLayout *UserGUI::createComboBox() {
//    QHBoxLayout *comboBoxLayout = new QHBoxLayout;
//    QLabel *label = new QLabel("Choose the type of file for your shopping cart", this);
//    QComboBox *fileType = new QComboBox(this);
//    fileType->addItem("CSV");
//    fileType->addItem("HTML");
//    comboBoxLayout->addWidget(label);
//    comboBoxLayout->addWidget(fileType);
//
//    return comboBoxLayout;
//}
//
//QHBoxLayout *UserGUI::createUserButtons() {
//    QHBoxLayout* buttons = new QHBoxLayout;
//    QPushButton* browseTrenchCoatsButton = new QPushButton("Browse through available trench coats");
//    connect(browseTrenchCoatsButton, &QPushButton::clicked, this, &UserGUI::browseButtonClicked);
//    QPushButton* goToCartButton = new QPushButton("Go to shopping cart");
//    connect(goToCartButton, &QPushButton::clicked, this, &UserGUI::goshoppin);
//    buttons->addWidget(browseTrenchCoatsButton);
//    buttons->addWidget(goToCartButton);
//    return buttons;
//}
//
//QHBoxLayout *UserGUI::createSizeInputLayout() {
//    QHBoxLayout* layout = new QHBoxLayout;
//    QLabel* inputSizeLabel = new QLabel("Enter the size of the trench coat");
//    QLineEdit* sizeInput = new QLineEdit(this);
//    layout->addWidget(inputSizeLabel);
//    layout->addWidget(sizeInput);
//    return layout;
//}
//
//QHBoxLayout *UserGUI::createStackedWidgetLayout() {
//    QHBoxLayout* layout = new QHBoxLayout;
//    this->stackedWidget = new QStackedWidget;
//    QWidget* firstPage = new QWidget;
//    this->stackedWidget->addWidget(firstPage);
//    this->stackedWidget->setCurrentIndex(0);
//    layout->addWidget(this->stackedWidget);
//    return layout;
//}
//
//QHBoxLayout *UserGUI::createBrowsingButtons() {
//    QHBoxLayout* layout = new QHBoxLayout;
//    QPushButton* nextButton = new QPushButton("Next");
//    connect(nextButton, &QPushButton::clicked, this, &UserGUI::nextButtonClicked);
//    QPushButton* addToCartButton = new QPushButton("Add to Cart");
//    connect(addToCartButton, &QPushButton::clicked, this, &UserGUI::addToWatchListButtonClicked);
//    layout->addWidget(nextButton);
//    layout->addWidget(addToCartButton);
//    return layout;
//}
//
//void UserGUI::nextButtonClicked() {
//    if(this->stackedWidget->currentIndex() + 1 >= this->stackedWidget->count()) {
//        if (this->stackedWidget->count() != 0)
//            this->stackedWidget->setCurrentIndex(1);
//    }
//    else{
//        this->stackedWidget->setCurrentIndex(this->stackedWidget->currentIndex() + 1);
//    }
//}
//
//void UserGUI::addToWatchListButtonClicked() {
//
//}
//
//void UserGUI::browseButtonClicked() {
//    int noOfWidgets = this->stackedWidget->count();
//    for (int i = noOfWidgets - 1; i > 0; i--) {
//        QWidget * removedPage = this->stackedWidget->widget(i);
//        this->stackedWidget->removeWidget(this->stackedWidget->widget(i));
//        delete removedPage;
//    }
//
//    std::vector<Movie> trenches = this->service.getMoviesService();
//    int numberOfTrenches = trenches.size();
//    for (int i = 0; i < numberOfTrenches; i++) {
//        QWidget * newPage = new QWidget;
//        QVBoxLayout *pageLayout = new QVBoxLayout;
//        QTableWidget *trenchView = new QTableWidget;
//
//        QStringList header = {"Colour", "Size", "Price", "Quantity", "Photograph"};
//        trenchView->setColumnCount(5);
//        trenchView->setColumnWidth(4, 300);
//        trenchView->setHorizontalHeaderLabels(header);
//        int rowCount = trenchView->rowCount();
//        trenchView->insertRow(rowCount);
//        trenchView->setItem(rowCount, 0, new QTableWidgetItem(QString::fromStdString(trenches[i].getTitle())));
//        trenchView->setItem(rowCount, 1, new QTableWidgetItem(QString::fromStdString(trenches[i].getGenre())));
//        trenchView->setItem(rowCount, 2, new QTableWidgetItem(QString::number(trenches[i].getYear())));
//        trenchView->setItem(rowCount, 3, new QTableWidgetItem(QString::number(trenches[i].getLikes())));
//        trenchView->setItem(rowCount, 4, new QTableWidgetItem(QString::fromStdString(trenches[i].getTrailer())));
//
//        pageLayout->addWidget(trenchView);
//        newPage->setLayout(pageLayout);
//        this->stackedWidget->insertWidget(i + 1, newPage);
//    }
//    if (numberOfTrenches == 0) {
//        QMessageBox msgBox;
//        msgBox.setText("There are no trench coats available with that size!");
//        msgBox.exec();
//    }
//    else
//        this->stackedWidget->setCurrentIndex(1);
//}
//
//void UserGUI::goshoppin() {
//
//}




//void Service::generate10RandomMovies(){
//    std::vector<std::string> movieNames = {
//            "The Matrix", "Inception", "The Shawshank Redemption", "Pulp Fiction",
//            "Forrest Gump", "The Godfather", "Interstellar", "The Dark Knight",
//            "Schindler's List", "Fight Club", "The Lord of the Rings", "Titanic",
//            "Star Wars", "Jurassic Park", "Avatar", "The Lion King",
//            "Harry Potter", "The Avengers", "Gladiator", "Braveheart"
//    };
//
//    int moviesAdded = 0;
//
//    while (moviesAdded < 10) {
//        int randomIndex = rand() % movieNames.size();
//        std::string title = movieNames[randomIndex];
//
//        std::string genre;
//        int genreIndex = rand() % 5;
//        if (genreIndex == 0) {
//            genre = "Action";
//        } else if (genreIndex == 1) {
//            genre = "Comedy";
//        } else if (genreIndex == 2) {
//            genre = "Drama";
//        } else if (genreIndex == 3) {
//            genre = "Romance";
//        } else {
//            genre = "Sci-Fi";
//        }
//
//        int year = 1970 + rand() % 54;
//        int likes = rand() % 10000;
//        std::string trailer = "https://www.youtube.com/trailer" + std::to_string(rand() % 1000);
//
//        Movie movie = Movie(title, genre, year, likes, trailer);
//        if (addService(movie) == 1) {
//            //addService(movie);
//            moviesAdded += 1;
//        }
//    }
//}


//UserGUI::UserGUI(Service& _service, QWidget *parent)
//        : service(_service), QWidget(parent) {
////    QHBoxLayout* comboBoxLayout = this->createComboBox();
////    QLabel* userModeTitle = new QLabel("User mode!", this);
////    QVBoxLayout* movieLayout = new QVBoxLayout(this);
////    movieLayout->addWidget(userModeTitle, 0, Qt::AlignCenter);
////
////    movieLayout->addLayout(comboBoxLayout);
////    QHBoxLayout* buttons = this->createUserButtons();
////    QHBoxLayout* sizeInputLayout = this->createGenreInputLayout();
////    QPushButton* closeButton = new QPushButton("EXIT");
////    connect(closeButton, &QPushButton::clicked, this, &UserGUI::closeButtonClicked);
////    QHBoxLayout* MovieStackedWidget = this->createStackedWidgetLayout();
////    QHBoxLayout* browsingButtons = this->createBrowsingButtons();
////
////    movieLayout->addLayout(buttons);
////    movieLayout->addLayout(sizeInputLayout);
////    movieLayout->addLayout(MovieStackedWidget);
////    movieLayout->addLayout(browsingButtons);
////    movieLayout->addWidget(closeButton);
////
////    this->setLayout(movieLayout);
//
//
//
//
////    QVBoxLayout* movieLayout = new QVBoxLayout(this);
////
////    QLabel* userModeTitle = new QLabel("User mode!", this);
////    movieLayout->addWidget(userModeTitle, 0, Qt::AlignCenter);
////
////    QHBoxLayout* comboBoxLayout = this->createComboBox();
////    movieLayout->addLayout(comboBoxLayout);
////
////    QHBoxLayout* buttons = this->createUserButtons();
////    movieLayout->addLayout(buttons);
////
////    QHBoxLayout* genreInputLayout = this->createGenreInputLayout();
////    movieLayout->addLayout(genreInputLayout);
////
////    QHBoxLayout* movieStackedWidget = this->createStackedWidgetLayout();
////    movieLayout->addLayout(movieStackedWidget);
////
////    QHBoxLayout* browsingButtons = this->createBrowsingButtons();
////    movieLayout->addLayout(browsingButtons);
////
////    QPushButton* closeButton = new QPushButton("EXIT");
////    connect(closeButton, &QPushButton::clicked, this, &UserGUI::closeButtonClicked);
////    movieLayout->addWidget(closeButton);
////
////    this->setLayout(movieLayout);
////
////    // Connect the genre input change to the slot
////    connect(genreInput, &QLineEdit::textChanged, this, &UserGUI::genreInputChanged);
//
//
//    QVBoxLayout* movieLayout = new QVBoxLayout(this);
//
//    QLabel* userModeTitle = new QLabel("User mode!", this);
//    movieLayout->addWidget(userModeTitle, 0, Qt::AlignCenter);
//
//    QHBoxLayout* comboBoxLayout1 = this->createComboBoxLayout();
//    movieLayout->addLayout(comboBoxLayout1);
//
////    QHBoxLayout* comboBoxLayout = this->createComboBox();
////    movieLayout->addLayout(comboBoxLayout);
//
//    QHBoxLayout* buttons = this->createUserButtons();
//    movieLayout->addLayout(buttons);
//
//    QHBoxLayout* genreInputLayout = this->createGenreInputLayout();
//    movieLayout->addLayout(genreInputLayout);
//
//    QHBoxLayout* movieStackedWidget = this->createStackedWidgetLayout();
//    movieLayout->addLayout(movieStackedWidget);
//
//    QHBoxLayout* browsingButtons = this->createBrowsingButtons();
//    movieLayout->addLayout(browsingButtons);
//
//    QVBoxLayout* watchlistLayout = this->createWatchlistLayout();
//    movieLayout->addLayout(watchlistLayout);
//
//    QHBoxLayout* openFileButtonLayout = this->createOpenFileButtonLayout();
//    movieLayout->addLayout(openFileButtonLayout);
//
////    QHBoxLayout* fileTypeLayout = new QHBoxLayout;
////    QLabel* fileTypeLabel = new QLabel("Choose the type of file for your watchlist", this);
////    QComboBox* fileTypeComboBox = new QComboBox(this);
////    fileTypeComboBox->addItem("CSV");
////    fileTypeComboBox->addItem("HTML");
////    fileTypeLayout->addWidget(fileTypeLabel);
////    fileTypeLayout->addWidget(fileTypeComboBox);
////    movieLayout->addLayout(fileTypeLayout);
////
////    // Connect the combo box signal to a slot to handle file type selection
////    connect(fileTypeComboBox, QOverload<int>::of(&QComboBox::activated),
////            this, [this](int index) {
////                if (index == 0) {
////                    service.setTypeOfWatchList(new CSVWatchList("CSVwatchlist.csv"));
////                } else if (index == 1) {
////                    service.setTypeOfWatchList(new HTMLWatchList("HTMLwatchlist.html"));
////                }
////            });
//
//
//    // Create the service object passing the chosen WatchListType
//    //Service service("Movies.txt");
//    //service.setTypeOfWatchList(createWatchList(watchListType));
//
//    QPushButton* closeButton = new QPushButton("EXIT");
//    connect(closeButton, &QPushButton::clicked, this, &UserGUI::closeButtonClicked);
//    movieLayout->addWidget(closeButton);
//
//    this->setLayout(movieLayout);
//
//}
//
//void UserGUI::populateWatchlist() {
//    watchlistWidget->clear();
//    std::vector<Movie> movies = service.getMoviesTheUserLikes();
//    for (const Movie& movie : movies) {
//        watchlistWidget->addItem(QString::fromStdString(movie.getTitle()));
//    }
//}
//
//
//QVBoxLayout* UserGUI::createWatchlistLayout() {
//    QVBoxLayout* watchlistLayout = new QVBoxLayout;
//
//    watchlistWidget = new QListWidget(this);
//    watchlistLayout->addWidget(watchlistWidget);
//
//    QPushButton* deleteButton = new QPushButton("Delete Selected Movie", this);
//    connect(deleteButton, &QPushButton::clicked, this, &UserGUI::deleteSelectedMovie);
//    watchlistLayout->addWidget(deleteButton);
//
//    return watchlistLayout;
//}
//
//void UserGUI::deleteSelectedMovie() {
//    QListWidgetItem* selectedItem = watchlistWidget->currentItem();
//    if (!selectedItem) {
//        QMessageBox::warning(this, "Delete Movie", "No movie selected!");
//        return;
//    }
//
////    int index = watchlistWidget->row(selectedItem);
////    try {
////        service.removeWatchList(index);
////        delete selectedItem;
////        QMessageBox::information(this, "Delete Movie", "Movie deleted from watchlist!");
////    } catch (const std::exception& e) {
////        QMessageBox::critical(this, "Error", QString::fromStdString(e.what()));
////    } catch (...) {
////        QMessageBox::critical(this, "Error", "An unknown error occurred.");
////    }
//
//    int selectedIndex = watchlistWidget->row(selectedItem);
//
//    // Ask the user if they want to like the movie before deleting it
//    QMessageBox::StandardButton reply;
//    reply = QMessageBox::question(this, "Like Movie", "Do you want to like this movie before deleting?",
//                                  QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
//
//    if (reply == QMessageBox::Cancel) {
//        return; // User cancelled the delete operation
//    }
//
//    if (reply == QMessageBox::Yes) {
//        service.increaseLikesOfMovie(selectedIndex);
//    }
//
//    service.removeWatchList(selectedIndex);
//    delete selectedItem; // Remove the item from the QListWidget
//
//}
//
//
//void UserGUI::watchlistFileTypeHandler() {
//    if (this->watchFileType->currentText() == "CSV")
////    QString selectedFormat = this->watchFileType->currentText();
////
////    if (selectedFormat == "Select Format") {
////        QMessageBox::warning(this, "Warning", "Please select a file type for the watchlist export.");
////        return;
////    }
////
////    if (selectedFormat == "CSV")
//        this->service.setTypeOfWatchList(new CSVWatchList{"watchlist.csv"});
//    else
//        this->service.setTypeOfWatchList(new HTMLWatchList{"watchlist.html"});
//}
//
//QHBoxLayout* UserGUI::createComboBoxLayout() {
//    auto* comboBoxLayout = new QHBoxLayout;
//    auto* label = new QLabel("Format of Watchlist Export", this);
//    watchFileType = new QComboBox(this);
//    watchFileType->addItem("Select Format");
//    watchFileType->addItem("CSV");
//    watchFileType->addItem("HTML");
//    comboBoxLayout->addWidget(label);
//    comboBoxLayout->addWidget(watchFileType);
//
//    // Connect the combo box signal to the slot to handle file type selection
//    connect(watchFileType, &QComboBox::currentTextChanged, this, &UserGUI::watchlistFileTypeHandler);
//
//    return comboBoxLayout;
//}
//
//void UserGUI::closeButtonClicked() {
//    emit CloseUserWindow();
//}
//
//QHBoxLayout *UserGUI::createComboBox() {
//    QHBoxLayout *comboBoxLayout = new QHBoxLayout;
//    QLabel *label = new QLabel("Choose the type of file for your watchlist", this);
//    QComboBox *fileType = new QComboBox(this);
//    fileType->addItem("CSV");
//    fileType->addItem("HTML");
//    comboBoxLayout->addWidget(label);
//    comboBoxLayout->addWidget(fileType);
//
//    return comboBoxLayout;
//}
//
//
//QHBoxLayout *UserGUI::createUserButtons() {
////    QHBoxLayout* buttons = new QHBoxLayout;
////    QPushButton* browseMoviesButton = new QPushButton("Browse through available movies");
////    connect(browseMoviesButton, &QPushButton::clicked, this, &UserGUI::browseButtonClicked);
////    QPushButton* goToWatchlistButton = new QPushButton("Go to watch list");
////    connect(goToWatchlistButton, &QPushButton::clicked, this, &UserGUI::watchList);
////    buttons->addWidget(browseMoviesButton);
////    buttons->addWidget(goToWatchlistButton);
////    return buttons;
//    QHBoxLayout* layout = new QHBoxLayout;
//    QLabel* inputSizeLabel = new QLabel("Enter genre:");
//    genreInput = new QLineEdit(this); // Initialize genre input
//    layout->addWidget(inputSizeLabel);
//    layout->addWidget(genreInput);
//    return layout;
//}
//
//
//
//QHBoxLayout *UserGUI::createGenreInputLayout() {
////    QHBoxLayout* layout = new QHBoxLayout;
////    QLabel* inputSizeLabel = new QLabel("Enter genre");
////    QLineEdit* genreInput = new QLineEdit(this);
////    layout->addWidget(inputSizeLabel);
////    layout->addWidget(genreInput);
////    return layout;
//
//    QHBoxLayout* layout = new QHBoxLayout;
//
//    // Add OK button
//    QPushButton* okButton = new QPushButton("OK");
//    connect(okButton, &QPushButton::clicked, this, &UserGUI::okButtonClicked);
//    layout->addWidget(okButton);
//
//    return layout;
//}
//
//void UserGUI::okButtonClicked() {
//    QString genre = genreInput->text();
//    std::string genreStr = genre.toStdString();
//
//    // Get movies by genre
//    if (genreStr.empty()) {
//        movies = service.getMoviesService(); // Get all movies if no genre is specified
//    } else {
//        movies = service.getMoviesByGenre(genreStr); // Get movies by genre
//    }
//
//    currentMovieIndex = 0; // Reset the current movie index
//    updateMovieDisplay(); // Display the first movie
//}
//
//QHBoxLayout *UserGUI::createStackedWidgetLayout() {
//    QHBoxLayout* layout = new QHBoxLayout;
//    this->stackedWidget = new QStackedWidget;
//    QWidget* firstPage = new QWidget;
//    this->stackedWidget->addWidget(firstPage);
//    this->stackedWidget->setCurrentIndex(0);
//    layout->addWidget(this->stackedWidget);
//    return layout;
//}
//
//QHBoxLayout *UserGUI::createBrowsingButtons() {
//    QHBoxLayout* layout = new QHBoxLayout;
//    QPushButton* nextButton = new QPushButton("Next");
//    connect(nextButton, &QPushButton::clicked, this, &UserGUI::nextButtonClicked);
//    QPushButton* addToWatchlistButton = new QPushButton("Add to watch list");
//    connect(addToWatchlistButton, &QPushButton::clicked, this, &UserGUI::addToWatchListButtonClicked);
//    layout->addWidget(nextButton);
//    layout->addWidget(addToWatchlistButton);
//    return layout;
//}
//
//void UserGUI::nextButtonClicked() {
////    if(this->stackedWidget->currentIndex() + 1 >= this->stackedWidget->count()) {
////        if (this->stackedWidget->count() != 0)
////            this->stackedWidget->setCurrentIndex(1);
////    }
////    else{
////        this->stackedWidget->setCurrentIndex(this->stackedWidget->currentIndex() + 1);
////    }
//    if (!movies.empty()) {
//        currentMovieIndex = (currentMovieIndex + 1) % movies.size();
//        updateMovieDisplay();
//    }
//}
//
//void UserGUI::addToWatchListButtonClicked() {
//    if (movies.empty()) {
//        QMessageBox::warning(this, "Error", "No movies to add to the watchlist!");
//        return;
//    }
//    QString selectedFormat = this->watchFileType->currentText();
//
//    if (selectedFormat == "Select Format") {
//        QMessageBox::warning(this, "Warning", "Please select a file type for the watchlist export.");
//        return;
//    }
//
//    // Check if currentMovieIndex is within bounds
//    if (currentMovieIndex < 0 || currentMovieIndex >= movies.size()) {
//        QMessageBox::warning(this, "Error", "Invalid movie index!");
//        return;
//    }
//
//    qDebug() << "Adding movie to watchlist. Current index:" << currentMovieIndex;
//
//    try {
//        Movie currentMovie = movies[currentMovieIndex];
//        qDebug() << "Adding movie to watchlist:" << QString::fromStdString(currentMovie.getTitle());
//        service.addMovieToWatchList(currentMovie);
//        QMessageBox::information(this, "Watchlist", "Movie added to watchlist!");
//        populateWatchlist();
//    } catch (const std::exception& e) {
//        QMessageBox::critical(this, "Error", QString::fromStdString(e.what()));
//    } catch (...) {
//        QMessageBox::critical(this, "Error", "An unknown error occurred.");
//    }
//}
//
//
//void UserGUI::genreInputChanged() {
//    QString genre = genreInput->text();
//    std::string genreStr = genre.toStdString();
//
//    // Get movies by genre
//    if (genreStr.empty()) {
//        movies = service.getMoviesService(); // Get all movies if no genre is specified
//    } else {
//        movies = service.getMoviesByGenre(genreStr); // Get movies by genre
//    }
//
//    currentMovieIndex = 0; // Reset the current movie index
//    updateMovieDisplay(); // Display the first movie
//}
//
//void UserGUI::updateMovieDisplay() {
//    // Remove all pages except the first one
//    int noOfWidgets = stackedWidget->count();
//    for (int i = noOfWidgets - 1; i > 0; i--) {
//        QWidget* removedPage = stackedWidget->widget(i);
//        stackedWidget->removeWidget(removedPage);
//        delete removedPage;
//    }
//
//    // Add the current movie to the stacked widget
//    if (!movies.empty()) {
//        Movie& movie = movies[currentMovieIndex];
//        QWidget* newPage = new QWidget;
//        QVBoxLayout* pageLayout = new QVBoxLayout;
//
//        QTableWidget* moviesTable = new QTableWidget;
//        moviesTable->setColumnCount(5);
//        QStringList header = { "Title", "Genre", "Trailer", "Year Release", "Nr likes" };
//        moviesTable->setHorizontalHeaderLabels(header);
//
//        int rowCount = moviesTable->rowCount();
//        moviesTable->insertRow(rowCount);
//        moviesTable->setItem(rowCount, 0, new QTableWidgetItem(QString::fromStdString(movie.getTitle())));
//        moviesTable->setItem(rowCount, 1, new QTableWidgetItem(QString::fromStdString(movie.getGenre())));
//        moviesTable->setItem(rowCount, 2, new QTableWidgetItem(QString::fromStdString(movie.getTrailer())));
//        moviesTable->setItem(rowCount, 3, new QTableWidgetItem(QString::number(movie.getYear())));
//        moviesTable->setItem(rowCount, 4, new QTableWidgetItem(QString::number(movie.getLikes())));
//
//        pageLayout->addWidget(moviesTable);
//        newPage->setLayout(pageLayout);
//        stackedWidget->addWidget(newPage);
//        stackedWidget->setCurrentIndex(1);
//    } else {
//        // Show a message if there are no movies
//        QMessageBox msgBox;
//        msgBox.setText("There are no movies available with that genre!");
//        msgBox.exec();
//    }
//}
//
//void UserGUI::browseButtonClicked() {
//    QString genreFromUser = this->genreInput->text();  // Retrieve the genre input from the user
//
//    // Filter movies by genre
//    std::vector<Movie> movies;
//    if (!genreFromUser.isEmpty()) {
//        movies = this->service.getMoviesByGenre(genreFromUser.toStdString());
//    } else {
//        // If no genre entered, display all movies
//        movies = this->service.getMoviesService();
//    }
//
//    int noOfWidgets = this->stackedWidget->count();
//    for (int i = noOfWidgets - 1; i > 0; i--) {
//        QWidget * removedPage = this->stackedWidget->widget(i);
//        this->stackedWidget->removeWidget(this->stackedWidget->widget(i));
//        delete removedPage;
//    }
//
//    //std::vector<Movie> movie = this->service.getMoviesService();
//    int numberOfMovies = movies.size();
//    for (int i = 0; i < numberOfMovies; i++) {
//        QWidget * newPage = new QWidget;
//        QVBoxLayout *pageLayout = new QVBoxLayout;
//        QTableWidget *moviesTable = new QTableWidget;
//
//        QStringList header={"Title", "Genre" ,"Trailer", "Year Release" , "Nr likes"};
//        moviesTable->setColumnCount(5);
//        moviesTable->setColumnWidth(4, 300);
//        moviesTable->setHorizontalHeaderLabels(header);
//        int rowCount = moviesTable->rowCount();
//        moviesTable->insertRow(rowCount);
//        moviesTable->setItem(rowCount, 0, new QTableWidgetItem(QString::fromStdString(movies[i].getTitle())));
//        moviesTable->setItem(rowCount, 1, new QTableWidgetItem(QString::fromStdString(movies[i].getGenre())));
//        moviesTable->setItem(rowCount, 2, new QTableWidgetItem(QString::fromStdString(movies[i].getTrailer())));
//        moviesTable->setItem(rowCount, 3, new QTableWidgetItem(QString::number(movies[i].getYear())));
//        moviesTable->setItem(rowCount, 4, new QTableWidgetItem(QString::number(movies[i].getLikes())));
//
//        pageLayout->addWidget(moviesTable);
//        newPage->setLayout(pageLayout);
//        this->stackedWidget->insertWidget(i + 1, newPage);
//    }
//    if (numberOfMovies == 0) {
//        QMessageBox msgBox;
//        msgBox.setText("There are no movies available with that genre!");
//        msgBox.exec();
//    }
//    else
//        this->stackedWidget->setCurrentIndex(1);
//}
//
//void UserGUI::watchList() {
//
//}
//QHBoxLayout* UserGUI::createOpenFileButtonLayout() {
//    QHBoxLayout* buttonLayout = new QHBoxLayout;
//    QPushButton* openFileButton = new QPushButton("Open Watchlist File", this);
//
//    connect(openFileButton, &QPushButton::clicked, this, &UserGUI::openWatchlistFile);
//
//    buttonLayout->addWidget(openFileButton);
//    return buttonLayout;
//}
//
//void UserGUI::openWatchlistFile() {
//    QString selectedFormat = this->watchFileType->currentText();
//
//    if (selectedFormat == "Select Format") {
//        QMessageBox::warning(this, "Warning", "Please select a file type for the watchlist export.");
//        return;
//    }
//    try {
//        service.displayPlaylist();
//    } catch (const std::exception& e) {
//        QMessageBox::critical(this, "Error", QString::fromStdString(e.what()));
//    } catch (...) {
//        QMessageBox::critical(this, "Error", "An unknown error occurred.");
//    }
//}