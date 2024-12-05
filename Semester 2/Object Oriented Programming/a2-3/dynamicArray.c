//
// Created by mara on 3/16/2024.
//

#include "dynamicArray.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

DynamicArray *createDynamicArray(int capacity) {
    DynamicArray *dynamicArray = (DynamicArray*)malloc(sizeof(DynamicArray));
    if (dynamicArray != NULL) {
        dynamicArray->current_length = 0;
        dynamicArray->capacity = capacity;
        dynamicArray->medicine = (TElem *)malloc(capacity * sizeof(TElem));
        if (dynamicArray->medicine == NULL) {
            free(dynamicArray);
            dynamicArray = NULL;
        }
    }
    return dynamicArray;
}

void destroyDynamicArray(DynamicArray *dynamicArray) {
    if (dynamicArray != NULL) {

        for (int i = 0; i < dynamicArray->current_length; i++) {
            DestroyMedicine(&dynamicArray->medicine[i]);
        }
        dynamicArray->current_length = 0;
        free(dynamicArray->medicine);
        dynamicArray->medicine = NULL;
        free(dynamicArray);
    }
}


void addElementDynamicArray(DynamicArray *dynamicArray, TElem* medicine) {
    if (dynamicArray != NULL) {
        if (dynamicArray->current_length == dynamicArray->capacity)
            resizeDynamicArray(dynamicArray);

        dynamicArray->medicine[dynamicArray->current_length] = *medicine;
        dynamicArray->current_length++;
    }
}

void updateDynamicArray(DynamicArray *dynamicArray, Medicine* medicine){
    int position_to_be_updated;
    position_to_be_updated = checkIfInDynamicArray(dynamicArray, medicine->name, medicine->concentration);
    dynamicArray->medicine[position_to_be_updated].quantity += medicine->quantity;
}

int checkIfInDynamicArray(DynamicArray *dynamicArray, char medname[], int concentration){
    for (int i = 0; i < dynamicArray->current_length; i++) {
        if (strcmp(dynamicArray->medicine[i].name, medname) == 0 && dynamicArray->medicine[i].concentration == concentration) {
            return i;
        }
    }
    return -1;
}

void resizeDynamicArray(DynamicArray *dynamicArray) {
    if (dynamicArray != NULL) {
        dynamicArray->capacity *= 2;
        dynamicArray->medicine = (TElem *)realloc(dynamicArray->medicine, getCapacity(dynamicArray) * sizeof(TElem));
    }
}

int getLengthArray(DynamicArray *dynamicArray) {
    return dynamicArray->current_length;
}

TElem* getMedicine (DynamicArray *dynamicArray, int position){
    if (dynamicArray == NULL)
        return NULL;
    if (position < 0 || position >= dynamicArray->current_length)
        return NULL;
    return &dynamicArray->medicine[position];
}


int getCapacity(DynamicArray *dynamicArray) {
    return dynamicArray->capacity;
}

Medicine* getMedicineByName(DynamicArray* dynamicArray, char* name) {
    if (dynamicArray == NULL || name == NULL)
        return NULL;

    for (int i = 0; i < dynamicArray->current_length; i++) {
        Medicine* medicine = (Medicine*)getMedicine(dynamicArray, i);
        if (strcmp(medicine->name, name) == 0) {
            return medicine;
        }
    }

    return NULL;
}


void deleteElementDynamicArray(DynamicArray *dynamicArray,char medname[]){
    for(int i = 0; i < dynamicArray->current_length; i++) {
        if (strcmp(dynamicArray->medicine[i].name, medname) == 0){
            for(int j = i; j < dynamicArray->current_length; j++){
                dynamicArray->medicine[j] = dynamicArray->medicine[j + 1];
            }
            dynamicArray->current_length--;
        }
    }
}


void DeleteMedicinePosition(DynamicArray *dynamicArray, int pos){
    if (dynamicArray == NULL || pos < 0 || pos >= dynamicArray->current_length) {
        return;
    }

    for(int i = 0; i < dynamicArray->current_length; i++){
        if (i==pos){
            for(int j = i; j < dynamicArray->current_length; j++){
                dynamicArray->medicine[j] = dynamicArray->medicine[j + 1];
            }
            dynamicArray->current_length--;
        }
    }
}

int getCurrentLength(DynamicArray *dynamicArray) {
    if (dynamicArray != NULL) {
        return dynamicArray->current_length;
    }
    return -1;
}
