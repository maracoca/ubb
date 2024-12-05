//
// Created by mara on 3/5/2024.
//
#include <stdio.h>
#include "repository.h"
#include "domain.h"
#include "service.h"
#include "ui.h"
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

UI *createUI(MedicineService *service){
    UI* ui = (UI*)malloc(sizeof(UI));
    ui->service = service;
    return ui;
}

void destroyUI(UI *ui){
    DestroyService(ui->service);
    free(ui);
}


int ui(MedicineService* service){
    while (true){
        printf("What would you like to do next? \n");
        printf("1. Add or update medicine. \n");
        printf("2. Delete medicine. \n");
        printf("3. Update medicine. \n");
        printf("4. See all available medicines containing a given string. \n");
        printf("5. See all medicines that are short in supply. \n");
        printf("6. Undo last operation. \n");
        printf("7. Redo last operation. \n");
        printf("8. Exit. \n");

        int user_option;
        scanf("%d", &user_option);

        if (user_option == 1){
            char name[30];
            int concentration, quantity, price;

            printf("Add a name.");
            getchar();
            fgets(name, sizeof(name), stdin);
            name[strlen(name) - 1] = '\0';
            if (strcmp(name, "\0") == 0) {
                printf("Please add a name \n");

                do {
                    printf("Add a name.");
                    fgets(name, sizeof(name), stdin);
                    name[strlen(name) - 1] = '\0';
                    if (strcmp(name, "\0") == 0)
                        printf("Please add a name \n");
                } while (strcmp(name, "\0") == 0);
            }

            do {
                printf("Add a concentration.");
                scanf("%d", &concentration);
                if (concentration < 0)
                    printf("Concentration must be a positive number \n");
            }while (concentration < 0);

            do {
                printf("Add a quantity.");
                scanf("%d", &quantity);
                if (quantity < 0)
                    printf("Quantity must be a positive number \n");
            }while (quantity < 0);

            do {
                printf("Add a price.");
                scanf("%d", &price);
                if (price < 0)
                    printf("Price must be a positive number \n");
            }while (price < 0);

            ServiceAdd(service, name, concentration, quantity, price);

            Medicine* allMedicines = GetAllMedicine(service);
            for (int i=0; i<service->repository->dynamicArray->current_length; i++) {
                char *medicineString = ToString(allMedicines[i]);
                printf("%s", medicineString);
                free(medicineString);
            }
        }

        else if (user_option == 2) {
            char name[30];

            printf("Add the name of the medicine that you want to remove.");
            getchar();
            fgets(name, sizeof(name), stdin);
            name[strlen(name) - 1] = '\0';
            if (strcmp(name, "\0") == 0) {
                printf("Please add a name \n");

                do {
                    printf("Add the name of the medicine that you want to remove.");
                    fgets(name, sizeof(name), stdin);
                    name[strlen(name) - 1] = '\0';
                    if (strcmp(name, "\0") == 0)
                        printf("Please add a name \n");
                } while (strcmp(name, "\0") == 0);
            }

            ServiceDelete(service, name);
            //PrintAll(&repository);
            //char buffer[50];
            Medicine *allMedicines = GetAllMedicine(service);
            for (int i = 0; i < service->repository->dynamicArray->current_length; i++) {
                char *medicineString = ToString(allMedicines[i]);
                printf("%s", medicineString);
                free(medicineString);
            }
        }

        else if (user_option == 3) {
            char name[30];
            int concentration, quantity, price;

            printf("Add a name.");
            getchar();
            fgets(name, sizeof(name), stdin);
            name[strlen(name) - 1] = '\0';
            if (strcmp(name, "\0") == 0) {
                printf("Please add a name \n");

                do {
                    printf("Add a name.");
                    fgets(name, sizeof(name), stdin);
                    name[strlen(name) - 1] = '\0';
                    if (strcmp(name, "\0") == 0)
                        printf("Please add a name \n");
                } while (strcmp(name, "\0") == 0);
            }

            do {
                printf("Add a concentration.");
                scanf("%d", &concentration);
                if (concentration < 0)
                    printf("Concentration must be a positive number \n");
            }while (concentration < 0);

            do {
                printf("Add a quantity.");
                scanf("%d", &quantity);
                if (quantity < 0)
                    printf("Quantity must be a positive number \n");
            }while (quantity < 0);

            do {
                printf("Add a price.");
                scanf("%d", &price);
                if (price < 0)
                    printf("Price must be a positive number \n");
            }while (price < 0);

            ServiceUpdate(service, name, concentration, quantity, price);

            Medicine *allMedicines = GetAllMedicine(service);
            for (int i = 0; i < service->repository->dynamicArray->current_length; i++) {
                char *medicineString = ToString(allMedicines[i]);
                printf("%s", medicineString);
                free(medicineString);
            }
        }

        else if (user_option == 4){
            char string[30];

            printf("Add your string.");
            getchar();
            fgets(string, sizeof(string), stdin);
            string[strlen(string) - 1] = '\0';

            int count = 0;
            Medicine* filteredString = GetFilteredMedicinesService(service, string, &count);

            for (int i = 0; i < count; i++) {
                char *medicineString = ToString(filteredString[i]);
                printf("%s", medicineString);
                free(medicineString);
            }

            free(filteredString);
        }

        else if(user_option == 5){
            int quantity;
            do {
                printf("Add a quantity.");
                scanf("%d", &quantity);
                if (quantity < 0)
                    printf("Quantity must be a positive number \n");
            }while (quantity < 0);

            int count = 0;
            Medicine* filteredString = ShortInSupply(service,quantity, &count);
            for (int i = 0; i < count; i++) {
                char *medicineString = ToString(filteredString[i]);
                printf("%s", medicineString);
                free(medicineString);
            }
            free(filteredString);
        }

        else if(user_option == 6){
            if (undo(service))
                printf("Undo was successful.\n");
            else
                printf("No more undos to be made.\n");
        }

        else if(user_option == 7){
            if (redo(service)) {
                printf("Redo operation performed successfully.\n");
            } else
                printf("No operation to redo.\n");
        }

        else if (user_option == 8){
            printf("Bye! \n");
            return 0;
        }

        else
            printf("Incorrect input! \n");
    }
}

int main(){
    test();
    MedicineRepository* repository = CreateRepository();
    OperationsStack* undo_stack = CreateStack();
    MedicineService* service = CreateService(repository, undo_stack);
    UI* UI = createUI(service);
    TenEntries(service);
    //ui(repository);
    ui(UI->service);
    destroyUI(UI);
//    DestroyService(service);
//    DestroyRepository(repository);

    return 0;
}