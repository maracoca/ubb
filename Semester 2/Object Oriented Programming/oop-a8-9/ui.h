//
// Created by mara on 3/24/2024.
//

#ifndef OOP_A4_5_MARACOCA_UI_H
#define OOP_A4_5_MARACOCA_UI_H

#pragma once

#include "service.h"

class UI{

private:
    Service service;
public:
    UI();
    ~UI();
    int administrator();
    void initialMenu();
    void ui();
    void User();
};

#endif //OOP_A4_5_MARACOCA_UI_H
