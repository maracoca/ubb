//
// Created by mara on 5/20/2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_appGUI.h" resolved

#include "appgui.h"


GUI::GUI(Service &_service, QWidget *parent) : QMainWindow(parent), service(_service){
    this->buildGUI();
}

void GUI ::buildGUI() {
    this->setWindowTitle("Movies");

    this->mainWidget = new QStackedWidget{};
    this->setCentralWidget(this->mainWidget);


    this->setUpChooseMode();

}

void GUI::setUpChooseMode() {
    this->chooseModeWidget = new QWidget{};
    this->chooseModeLayout = new QVBoxLayout{};

    this->chooseModeLabel=new QLabel{"Choose mode"};
    this->chooseModeLayout->addWidget(this->chooseModeLabel, 0, Qt::AlignHCenter);

    this->adminButton=new QPushButton("Admin mode");
    this->chooseModeLayout->addWidget(this->adminButton);
    connect(this->adminButton,&QPushButton::clicked,this, &GUI::openAdminWindow);

    this->userButton=new QPushButton("User mode");
    this->chooseModeLayout->addWidget(this->userButton);
    connect(this->userButton,&QPushButton::clicked,this,&GUI::openUserWindow);

    this->chooseModeWidget->setLayout(this->chooseModeLayout);
    this->mainWidget->addWidget(this->chooseModeWidget);


}

void GUI::openMainWindow() {
    this->mainWidget->setCurrentIndex(this->mainWidget->indexOf(this->chooseModeWidget));

}
void GUI::openAdminWindow()  {
    this->adminWindow = new AdminGUI(this->service, this);
    connect(this->adminWindow, SIGNAL(CloseAdminWindow()), this, SLOT(openMainWindow()));
    this->mainWidget->addWidget(this->adminWindow);
    this->mainWidget->setCurrentIndex(this->mainWidget->indexOf(this->adminWindow));
}

void GUI::openUserWindow() {
    this->userWindow = new UserGUI(this->service, this);
    connect(this->userWindow, SIGNAL(CloseUserWindow()), this, SLOT(openMainWindow()));
    this->mainWidget->addWidget(this->userWindow);
    this->mainWidget->setCurrentIndex(this->mainWidget->indexOf(this->userWindow));
}
GUI::~GUI () {

}