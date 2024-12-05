//
// Created by mara on 3/19/2024.
//

#ifndef A2_3_MARACOCA_UI_H
#define A2_3_MARACOCA_UI_H
#pragma once

#include "service.h"

typedef struct
{
    MedicineService *service;
} UI;

UI *createUI(MedicineService *service);

void destroyUI(UI *ui);

int ui(MedicineService* service);

int main();

#endif //A2_3_MARACOCA_UI_H
