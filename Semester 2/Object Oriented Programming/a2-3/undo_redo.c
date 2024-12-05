//
// Created by mara on 3/17/2024.
//

#include <stdlib.h>
#include <string.h>
#include "undo_redo.h"

Operation* CreateOperation(Medicine* medicine, char* operationType){
    Operation* operation = malloc(sizeof(Operation));

    if (operation == NULL)
        return NULL;

    operation->medicine = copyMedicine(medicine);

    if (operationType != NULL){
        operation->operationType = malloc(sizeof(char) * (strlen(operationType) + 1));

        if (operation->operationType == NULL)
        {
            free(operation);
            return NULL;
        }
        strcpy(operation->operationType, operationType);
    }
    else
        operation->operationType = NULL;

    return operation;
}

void destroyOperation(Operation* operation){
    DestroyMedicine(operation->medicine);
    free(operation->operationType);
    free(operation);
}


Operation* copyOperation(Operation* operation){
    if (operation == NULL)
        return NULL;
    Operation* copy = CreateOperation(operation->medicine, operation->operationType);
    return copy;
}



OperationsStack* CreateStack(){
    OperationsStack* operation_stack = malloc(sizeof(OperationsStack));

    if (operation_stack == NULL)
        return NULL;

    operation_stack->undo_stack = createDynamicArray(10);
    if (operation_stack->undo_stack == NULL)
    {
        free(operation_stack);
        return NULL;
    }

    operation_stack->redo_stack = createDynamicArray(10);
    if (operation_stack->redo_stack == NULL)
    {
        free(operation_stack);
        return NULL;
    }

    return operation_stack;
}

void destroyStack(OperationsStack* operation_stack){
    if (operation_stack == NULL)
        return;

    destroyDynamicArray(operation_stack->undo_stack);
    destroyDynamicArray(operation_stack->redo_stack);
    //free(operation_stack);
}

void push(OperationsStack* operation_stack, Operation* operation){
    if (operation_stack == NULL || operation == NULL)
        return;
    addElementDynamicArray(operation_stack->undo_stack, operation);
    //destroyDynamicArray(operation_stack->redo_stack);
}

Operation* pop(OperationsStack* operation_stack){
    if (operation_stack == NULL)
        return NULL;

    int last_position = operation_stack->undo_stack->current_length - 1;
    Operation* operation = (Operation *) getMedicine(operation_stack->undo_stack, last_position);

    Operation* lastOp = copyOperation(operation);
    DeleteMedicinePosition(operation_stack->undo_stack, last_position);
    return lastOp;
}


int isEmpty(OperationsStack* operation_stack){
    if (operation_stack == NULL)
        return 1;
    return (operation_stack->undo_stack->current_length == 0);
}


