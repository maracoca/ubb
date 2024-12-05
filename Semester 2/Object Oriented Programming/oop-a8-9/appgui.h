//
// Created by mara on 5/20/2024.
//

#ifndef OOP_A8_9_MARACOCA_APPGUI_H
#define OOP_A8_9_MARACOCA_APPGUI_H

#include "service.h"
#include <qwidget.h>
#include <qlistwidget.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qlayout.h>
#include <qlabel.h>
#include <QtWidgets/QMainWindow>
#include <QWidget>
#include <QVBoxLayout>
#include <QStackedWidget>
#include "admin.h"
#include "user.h"

class GUI : public QMainWindow{
Q_OBJECT
private:
    Service& service;
    void buildGUI();
    void setUpChooseMode();

private slots:
    void openAdminWindow();

    void openUserWindow();

    void openMainWindow();

public:
    GUI(Service& _service, QWidget* parent=nullptr);
    ~GUI();
private:
    AdminGUI* adminWindow;
    UserGUI* userWindow;
    QStackedWidget* mainWidget;

    QLabel* chooseModeLabel;
    QVBoxLayout* chooseModeLayout;
    QWidget* chooseModeWidget;

    QPushButton* userButton;
    QPushButton* adminButton;
    QVBoxLayout* chooseOutputLayout;

};

#endif //OOP_A8_9_MARACOCA_APPGUI_H
