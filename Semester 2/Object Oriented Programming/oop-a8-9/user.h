//
// Created by mara on 5/20/2024.
//

#ifndef OOP_A8_9_MARACOCA_USER_H
#define OOP_A8_9_MARACOCA_USER_H

#include <QWidget>
#include "service.h"
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMainWindow>
#include <QStackedWidget>
#include <QComboBox>
#include <QLineEdit>
#include <QTableWidget>
#include <QMessageBox>
#include <QListWidget>

class UserGUI : public QWidget{
Q_OBJECT
private:
    Service& service;
    QHBoxLayout* createComboBox();
    QHBoxLayout* createUserButtons();
    QHBoxLayout* createGenreInputLayout();
    QHBoxLayout* createStackedWidgetLayout();
    QHBoxLayout* createBrowsingButtons();
    QHBoxLayout* createComboBoxLayout();
    QHBoxLayout* createOpenFileButtonLayout();
    QVBoxLayout* createWatchlistLayout();
    QListWidget* watchlistWidget;
    QLineEdit* genreInput; // Keep track of the genre input
    int currentMovieIndex; // Index to keep track of the current movie in the browse list
    std::vector<Movie> movies; // Store the list of movies to browse
    //FileWatchList* watchListType;
    QComboBox *watchFileType;
public:
    //UserGUI(Service& _service, QWidget* parent=nullptr);
    UserGUI(Service& _service, QWidget *parent=nullptr);
    ~UserGUI(){};

    QStackedWidget* stackedWidget;
public slots:
    void closeButtonClicked();
    void nextButtonClicked();
    void addToWatchListButtonClicked();
    void deleteSelectedMovie();
    void openWatchlistFile();
    void watchlistFileTypeHandler();
    //void showWatchListButtonClicked();
    void okButtonClicked();
    void genreInputChanged();
    void updateMovieDisplay();
    void populateWatchlist();
signals:
    void CloseUserWindow();
};


#endif //OOP_A8_9_MARACOCA_USER_H
