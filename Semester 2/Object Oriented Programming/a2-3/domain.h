//
// Created by mara on 3/5/2024.
//

#ifndef A2_3_MARACOCA_DOMAIN_H
#define A2_3_MARACOCA_DOMAIN_H

#pragma once

typedef struct {
    char *name;
    int concentration;
    int quantity;
    int price;
}Medicine;

Medicine* CreateMedicine(char *name, int concentration, int quantity, int price);

char* ToString(Medicine medicine);

void DestroyMedicine(Medicine* medicine);

Medicine* copyMedicine(Medicine* medicine);

#endif //A2_3_MARACOCA_DOMAIN_H

