//
// Created by mara on 3/9/2024.
//

#ifndef A2_3_MARACOCA_SERVICE_H
#define A2_3_MARACOCA_SERVICE_H



#include "repository.h"
#include "undo_redo.h"

typedef struct {
    MedicineRepository* repository;
    OperationsStack* undoStack;
    OperationsStack* redoStack;
} MedicineService;

MedicineService* CreateService(MedicineRepository* repository, OperationsStack* undoStack);

void DestroyService(MedicineService* service);

void TenEntries(MedicineService* service);

void ServiceAdd(MedicineService* service, char *name, int concentration, int quantity, int price);

void ServiceUpdate(MedicineService* service, char *name, int concentration, int quantity, int price);

void ServiceDelete(MedicineService* service, char *name);

Medicine* GetAllMedicine(MedicineService* service);

Medicine* GetFilteredMedicinesService(MedicineService* service, char string[], int *count);

Medicine* SortedAsceding(MedicineService* service);

Medicine* ShortInSupply(MedicineService* service, int minimum_quantity, int *current_position);

int undo(MedicineService* service);

int redo(MedicineService* service);

void test();

#endif //A2_3_MARACOCA_SERVICE_H