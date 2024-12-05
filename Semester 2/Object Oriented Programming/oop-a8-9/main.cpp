//
// Created by mara on 3/24/2024.
//

//#include <QApplication>
#include "ui.h"
#include "appgui.h"
#include <QtWidgets/QApplication>
//#include "movieTest.h"
//#include "serviceTest.h"
//#include "repoTest.h"

int main(int argc, char *argv[]){
//    TestMovie::testMovie();
 //   TestService::testService();
//    TestRepository::testRepository();
    QApplication mainApplication(argc, argv);
//    UI ui;
//    ui.ui();
    Service service{"Movies.txt"};
    GUI g{service};
    g.show();
    //int* data = new int[100];
//    return 0;
    return mainApplication.exec();
}