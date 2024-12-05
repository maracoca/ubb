//
// Created by mara on 5/20/2024.
//

#ifndef ADMINGUI_H
#define ADMINGUI_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QTableWidget>
#include <QStringList>
#include <QListWidget>
#include "Service.h"
#include "Movie.h"
//#include "ValidationException.h"
//#include "RepositoryException.h"
//#include "MovieValidator.h"

class AdminGUI : public QWidget {
Q_OBJECT

public:
    AdminGUI(Service& _service, QWidget* parent = nullptr);
    ~AdminGUI() {};

public slots:
    void closeButtonClicked();
    void addButtonClicked();
    void deleteButtonClicked();
    void updateButtonClicked();

signals:
    void CloseAdminWindow();

private:
    Service& service;

    QVBoxLayout* mainAdminLayout;
    QHBoxLayout* moviesInfoLayout;
    QVBoxLayout* moviesInfo;
    QLabel* adminTitle;

    QHBoxLayout* buttonsLayout;
    QPushButton* addButton;
    QPushButton* deleteButton;
    QPushButton* updateButton;
    QPushButton* closeButton;

    QHBoxLayout* titleLayout;
    QLabel* titleLabel;
    QLineEdit* titleInput;

    QHBoxLayout* genreLayout;
    QLabel* genreLabel;
    QLineEdit* genreInput;

    QHBoxLayout* yearLayout;
    QLabel* yearLabel;
    QLineEdit* yearInput;

    QHBoxLayout* likesLayout;
    QLabel* likesLabel;
    QLineEdit* likesInput;

    QHBoxLayout* trailerLayout;
    QLabel* trailerLabel;
    QLineEdit* trailerInput;

    QTableWidget* moviesTable;
    QListWidget *moviesListWidget;

    void createAdminButtons();
    void createTitleLayout();
    void createGenreLayout();
    void createYearLayout();
    void createLikesLayout();
    void createTrailerLayout();
    void createTableWidget();
    Movie extractMovieInfo();
    void reloadMoviesTable();
    void createMoviesListWidget();
    void displaySelectedMovie();
};


#endif //OOP_A8_9_MARACOCA_ADMIN_H
