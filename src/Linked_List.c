/**********************
 * James Busch
 * 16/03/20
 * ver 0.01
 * 
 * This is the code for the Linked_list API
 **********************/

#include <stdio.h>
#include <stdlib.h>
#include "Linked_List.h"

List *initList(void (*delete)(void *toPrint), int(*compare)(const void *compOne, const void *compTwo), char* (*print)(void*)){
    if(delete == NULL || compare == NULL || print == NULL) return NULL;
    List *newList = malloc(sizeof(List));
    
    newList->head = NULL;
    newList->tail = NULL;

    newList->deleteData = delete;
    newList->compareData = compare;
    newList->printData = print;
}

void insertFront(void *data, List *list){
    if(data == NULL || list == NULL) return;
    Node *toAdd = malloc(sizeof(Node));
    toAdd->data = data;
    toAdd->behind = NULL;
    if(list->length == 0){
        toAdd->infront = NULL;
        list->head = toAdd;
        list->tail = toAdd;
    }else{
        list->head->behind = toAdd;
        list->head = toAdd;
    }
    list->length++;

}