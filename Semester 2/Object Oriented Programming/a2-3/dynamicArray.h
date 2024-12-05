//
// Created by mara on 3/16/2024.
//

#ifndef A2_3_MARACOCA_DYNAMICARRAY_H
#define A2_3_MARACOCA_DYNAMICARRAY_H
#pragma once

#include "domain.h"

typedef Medicine TElem;

typedef struct {
    TElem *medicine;
    int current_length;
    int capacity;
} DynamicArray;

DynamicArray *createDynamicArray(int capacity);

void destroyDynamicArray(DynamicArray *);

int checkIfInDynamicArray(DynamicArray *dynamicArray, char medname[], int concentration);

void updateDynamicArray(DynamicArray *dynamicArray, Medicine* medicine);

TElem* getMedicine (DynamicArray *dynamicArray, int position);

int getCapacity(DynamicArray *);

TElem* getMedicineByName (DynamicArray *dynamicArray, char* name);

void resizeDynamicArray(DynamicArray *);

void addElementDynamicArray(DynamicArray *dynamicArray, TElem* medicine);

void deleteElementDynamicArray(DynamicArray *dynamicArray,char medname[]);

void DeleteMedicinePosition(DynamicArray *dynamicArray, int pos);

int getCurrentLength(DynamicArray *dynamicArray);


#endif //A2_3_MARACOCA_DYNAMICARRAY_H
