//
// Created by mara on 3/17/2024.
//

#ifndef A2_3_MARACOCA_UNDO_REDO_H
#define A2_3_MARACOCA_UNDO_REDO_H
#pragma once

#include "domain.h"
#include "dynamicArray.h"

typedef struct
{
    Medicine* medicine;
    char* operationType;
} Operation;

Operation* CreateOperation(Medicine* medicine, char* operationType);

void destroyOperation(Operation* operation);

Operation* copyOperation(Operation * operation);

typedef struct
{
    DynamicArray* undo_stack;
    DynamicArray* redo_stack;
} OperationsStack;

OperationsStack* CreateStack();

void destroyStack(OperationsStack* operation_stack);

void push(OperationsStack* operation_stack, Operation* operation);

Operation* pop(OperationsStack* operation_stack);

Operation* popRedoStack(OperationsStack* operation_stack);

int isEmpty(OperationsStack* operation_stack);

int isEmptyRedo(OperationsStack* operation_stack);


#endif //A2_3_MARACOCA_UNDO_REDO_H
