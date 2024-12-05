//
// Created by mara on 3/5/2024.
//
#include "domain.h"
#include <string.h>
#include <stdio.h>
#include <malloc.h>


Medicine* CreateMedicine(char *name, int concentration, int quantity, int price)
{
    Medicine *medicine = (Medicine *)malloc(sizeof(Medicine));
    medicine->name = (char*)malloc(sizeof(char) * (strlen(name) + 1));
    strcpy(medicine->name, name);
    medicine->concentration = concentration;
    medicine->quantity = quantity;
    medicine->price = price;
    return medicine;
}

void DestroyMedicine(Medicine* medicine){
    if (medicine != NULL)
        free(medicine->name);
        free(medicine);
}

char* ToString(Medicine medicine) {
    char *string = (char *)malloc(sizeof(char) * 500);
    sprintf(string, "Name: %s, concentration: %d, quantity: %d, price: %d \n", medicine.name, medicine.concentration, medicine.quantity, medicine.price);
    return string;
}

Medicine* copyMedicine(Medicine* medicine){
    if (medicine == NULL)
        return NULL;

    Medicine* newMedicine = CreateMedicine(medicine->name, medicine->concentration, medicine->quantity, medicine->price);
    return newMedicine;
}
