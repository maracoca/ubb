//
// Created by mara on 3/9/2024.
//
#include "repository.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "domain.h"


MedicineRepository* CreateRepository() {
    //MedicineRepository repository;
    MedicineRepository* repository = (MedicineRepository*)malloc(sizeof(MedicineRepository));
    if (repository != NULL){
        repository->dynamicArray = createDynamicArray(10);
    }
    return repository;
}

void DestroyRepository(MedicineRepository* repository){
    if (repository != NULL){
        destroyDynamicArray(repository->dynamicArray);
        free(repository);
    }
}

void AddInRepository(Medicine* medicine, MedicineRepository* repository) {
    if (CheckIfInRepository(repository, medicine->name, medicine->concentration) == -1) {
        addElementDynamicArray(repository->dynamicArray, medicine);
    }
    else
    {
        int position_to_be_updated;
        position_to_be_updated = CheckIfInRepository(repository, medicine->name, medicine->concentration);
        repository->dynamicArray->medicine[position_to_be_updated].quantity += medicine->quantity;
    }
}


void UpdateInRepository(MedicineRepository *repository, Medicine* medicine){
//    int position_to_be_updated;
//    position_to_be_updated = CheckIfInRepository(repository, medicine->name, medicine->concentration);
//    repository->dynamicArray->medicine[position_to_be_updated].quantity += medicine->quantity;
    updateDynamicArray(repository->dynamicArray, medicine);
}

void DeleteInRepository(MedicineRepository* repository, char medname[]){
//    for(int i =0; i<repository->dynamicArray->current_length; i++) {
//        if (strcmp(repository->dynamicArray->medicine[i].name, medname) == 0){
//            for(int j=i; j<repository->dynamicArray->current_length; j++){
//                    repository->dynamicArray->medicine[j] = repository->dynamicArray->medicine[j + 1];
//            }
//            repository->dynamicArray->current_length--;
//        }
//    }
    deleteElementDynamicArray(repository->dynamicArray, medname);
}

int CheckIfInRepository(MedicineRepository* repository, char medname[], int concentration) {
    for (int i = 0; i < repository->dynamicArray->current_length; i++) {
        if (strcmp(repository->dynamicArray->medicine[i].name, medname) == 0 && repository->dynamicArray->medicine[i].concentration == concentration) {
            return i;
        }
    }
    return -1;
}


Medicine* GetAllMedicinesFromRepository(MedicineRepository * repository){
    return repository->dynamicArray->medicine;
}

Medicine* FindInRepository(MedicineRepository* repository, char medname[], int concentration) {
    for (int i = 0; i < repository->dynamicArray->current_length; i++) {
        if (strcmp(repository->dynamicArray->medicine[i].name, medname) == 0 && repository->dynamicArray->medicine[i].concentration == concentration) {
            return &repository->dynamicArray->medicine[i];
        }
    }
}


//void PrintAll(MedicineRepository* repository){
//    for (int i=0; i<repository->dynamicArray->current_length; i++)
//        printf("%s \n%d \n",  repository->medicines[i].name, repository->medicines[i].quantity);
//}