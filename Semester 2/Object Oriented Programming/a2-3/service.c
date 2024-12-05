//
// Created by mara on 3/9/2024.
//

#include "service.h"
#include "domain.h"
#include "repository.h"
#include "undo_redo.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

MedicineService* CreateService(MedicineRepository* repository, OperationsStack* undoStack) {
    //MedicineService* service;
    MedicineService *service = (MedicineService *)malloc(sizeof(MedicineService));
    service->repository = repository;
    service->undoStack = undoStack;

    service->redoStack = CreateStack();
    if (service->redoStack == NULL) {
        free(service);
        return NULL;
    }

    return service;
}

void DestroyService(MedicineService* service){
    if (service != NULL){
        DestroyRepository(service->repository);
        destroyStack(service->undoStack);
        //destroyStack(service->redoStack);
        free(service);
    }
}

void TenEntries(MedicineService* service){
    ServiceAdd(service, "ibuprofen", 100, 100, 50);
    ServiceAdd(service, "nurofen", 80, 150, 40);
    ServiceAdd(service, "aspirin", 200, 80, 45);
    ServiceAdd(service, "a", 200, 200, 45);
    ServiceAdd(service, "b", 200, 100, 45);
    ServiceAdd(service, "c", 200, 50, 45);
    ServiceAdd(service, "d", 200, 150, 45);
    ServiceAdd(service, "e", 200, 120, 45);
    ServiceAdd(service, "f", 200, 90, 45);
    ServiceAdd(service, "g", 200, 100, 45);
    ServiceUpdate(service, "g", 200, 50, 3);
}

void ServiceAdd(MedicineService* service, char *name, int concentration, int quantity, int price){
    Medicine* medicine = CreateMedicine(name, concentration, quantity, price);
    AddInRepository(medicine, service->repository);

    Operation* operation = CreateOperation(medicine, "add");
    push(service->undoStack, operation);

    //DestroyMedicine(medicine);
}

void ServiceUpdate(MedicineService* service, char *name, int concentration, int quantity, int price){
    Medicine *medicine = FindInRepository(service->repository, name, concentration);

    Operation* operation = CreateOperation(medicine, "update");
    push(service->undoStack, operation);

    Medicine* updated_medicine = CreateMedicine(name, concentration, quantity, price);
    UpdateInRepository(service->repository, updated_medicine);
}


void ServiceDelete(MedicineService *service, char *name){
    Medicine* medicine = getMedicineByName(service->repository->dynamicArray, name);
    Operation* operation = CreateOperation(medicine, "delete");
    push(service->undoStack, operation);
    DeleteInRepository(service->repository, name);
}


Medicine* GetAllMedicine(MedicineService* service){
    return GetAllMedicinesFromRepository(service->repository);
}


Medicine* GetFilteredMedicinesService(MedicineService* service, char string[], int* filteredCount) {
    Medicine* Sorted = SortedAsceding(service);
    Medicine* filteredMedicines = malloc(service->repository->dynamicArray->current_length * sizeof(Medicine));

    *filteredCount = 0;

    if (string[0] == '\0') {
        for (int i = 0; i < service->repository->dynamicArray->current_length; i++) {
            filteredMedicines[i] = Sorted[i];
        }
        *filteredCount = service->repository->dynamicArray->current_length;
    }

     else {
        for (int i = 0; i < service->repository->dynamicArray->current_length; i++) {
            if (strstr(Sorted[i].name, string) != NULL) {
                filteredMedicines[*filteredCount] = Sorted[i];
                (*filteredCount)++;
            }
        }
    }
    return filteredMedicines;
}

Medicine* SortedAsceding(MedicineService* service) {
    Medicine* allMedicines = GetAllMedicine(service);
    Medicine* sortedMedicines = malloc(service->repository->dynamicArray->current_length * sizeof(Medicine));

    for (int i = 0; i < service->repository->dynamicArray->current_length; i++) {
        sortedMedicines[i] = allMedicines[i];
    }

    Medicine temp;
    for (int i = 0; i < service->repository->dynamicArray->current_length - 1; i++) {
        for (int j = 0; j < service->repository->dynamicArray->current_length - i - 1; j++) {
            if (strcmp(sortedMedicines[j].name, sortedMedicines[j + 1].name) > 0) {
                temp = sortedMedicines[j];
                sortedMedicines[j] = sortedMedicines[j + 1];
                sortedMedicines[j + 1] = temp;
            }
        }
    }
    return sortedMedicines;
}

Medicine* ShortInSupply(MedicineService* service, int minimum_quantity, int *current_position){
    Medicine* allMedicines = GetAllMedicine(service);
    Medicine* filteredMedicines = malloc(service->repository->dynamicArray->current_length * sizeof(Medicine));

    for (int i = 0; i < service->repository->dynamicArray->current_length - 1; i++){
        if (allMedicines[i].quantity < minimum_quantity) {
            filteredMedicines[*current_position] = allMedicines[i];
            (*current_position)++;
        }
    }
    return filteredMedicines;
}


void ServiceUpdateAfterUndo(MedicineService* service, char *name, int concentration, int old_quantity){
    int position = CheckIfInRepository(service->repository, name, concentration);
    service->repository->dynamicArray->medicine[position].quantity = old_quantity;
}


int undo(MedicineService* service){
    if (isEmpty(service->undoStack)) {
        return 0;
    }

    Operation* operation = pop(service->undoStack);

    if (strcmp(operation->operationType, "add") == 0) {
        Medicine* medicine = operation->medicine;
        char name[50];
        strcpy(name, medicine->name);
        DeleteInRepository(service->repository, name);
    }
    else if(strcmp(operation->operationType, "delete") == 0){
        Medicine* medicine = operation->medicine;
        AddInRepository(medicine, service->repository);
    }
    else if(strcmp(operation->operationType, "update") == 0) {
        Medicine *medicine = operation->medicine;
        if (medicine != NULL) {
            Medicine *new_medicine = FindInRepository(service->repository, medicine->name, medicine->concentration);
            int new_quantity = new_medicine->quantity;

            ServiceUpdateAfterUndo(service, medicine->name, medicine->concentration, medicine->quantity);
            operation->medicine->quantity = new_quantity;
        }
    }

    push(service->redoStack, operation);
    destroyOperation(operation);

    return 1;
}


int redo(MedicineService* service){
    if (isEmpty(service->redoStack)) {
        return 0;
    }

    Operation* operation = pop(service->redoStack);

    if (strcmp(operation->operationType, "add") == 0) {
        Medicine* medicine = operation->medicine;
        ServiceAdd(service, medicine->name, medicine->concentration, medicine->quantity, medicine->price);
    }
    else if (strcmp(operation->operationType, "delete") == 0){
        Medicine* medicine = operation->medicine;
        ServiceDelete(service, medicine->name);
    }
    else if(strcmp(operation->operationType, "update") == 0){
        Medicine* medicine = operation->medicine;
        ServiceUpdateAfterUndo(service, medicine->name, medicine->concentration, medicine->quantity);
    }

    push(service->undoStack, operation);
    destroyOperation(operation);

    return 1;
}

void test(){
    MedicineRepository* repository = CreateRepository();
    OperationsStack* undo_stack = CreateStack();
    MedicineService* service = CreateService(repository, undo_stack);

    ServiceAdd(service, "lala", 100, 100, 10);
    assert(getCurrentLength(repository->dynamicArray) == 1);
    ServiceAdd(service, "nana", 200, 100, 10);
    assert(getCurrentLength(repository->dynamicArray) == 2);

    Medicine* medicine1 = CreateMedicine("lala", 100, 100, 10);
    Medicine* medicine2 = CreateMedicine("nana", 200, 100, 10);
    undo(service);
    assert(getCurrentLength(repository->dynamicArray) == 1);
    DestroyMedicine(medicine1);

    ServiceDelete(service, "lala");
    assert(getCurrentLength(repository->dynamicArray) == 0);
    DestroyMedicine(medicine2);

//    undo(service);
//    assert(getCurrentLength(repository->dynamicArray) == 1);


    ServiceUpdate(service, "lala", 100, 5, 10);
    int position = CheckIfInRepository(service->repository, "lala", 100);
//    assert(repository->dynamicArray->medicine[position].quantity == 105);
//    undo(service);
//    assert(repository->dynamicArray->medicine[position].quantity == 100);
//    redo(service);
//    assert(repository->dynamicArray->medicine[position].quantity == 105);
}

