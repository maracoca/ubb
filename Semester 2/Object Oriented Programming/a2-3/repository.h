//
// Created by mara on 3/9/2024.
//

#ifndef A2_3_MARACOCA_REPOSITORY_H
#define A2_3_MARACOCA_REPOSITORY_H

#pragma once
#include "domain.h"
#include "dynamicArray.h"

typedef struct {
    //Medicine* medicines;
    DynamicArray *dynamicArray;

    //int size;
}MedicineRepository;

MedicineRepository* CreateRepository();

void DestroyRepository(MedicineRepository* repository);

void AddInRepository(Medicine* medicine, MedicineRepository* repository);

void UpdateInRepository(MedicineRepository *repository, Medicine* medicine);

void DeleteInRepository(MedicineRepository* repository, char medname[]);

int CheckIfInRepository(MedicineRepository* repository, char medname[], int concentration);

Medicine* GetAllMedicinesFromRepository(MedicineRepository * repository);

Medicine* FindInRepository(MedicineRepository* repository, char medname[], int concentration);

void PrintAll(MedicineRepository* repository);

#endif //A2_3_MARACOCA_REPOSITORY_H