/**********************
 * James Busch
 * 24/03/20
 * ver 0.01
 * 
 * This is the code for the Linked_list API
 **********************/

#include <stdio.h>
#include <stdlib.h>
#include "Linked_List.h"

List *initList(void (*delete)(void *toPrint), int(*compare)(const void *compOne, const void *compTwo), char* (*print)(void *data)){
    if(delete == NULL || compare == NULL || print == NULL) return NULL;
    List *newList = malloc(sizeof(List));
    
    newList->length = 0;
    newList->head = NULL;
    newList->tail = NULL;

    newList->deleteData = delete;
    newList->compareData = compare;
    newList->printData = print;

    return newList;
}

bool insertFront(void *data, List *list){
    if(data == NULL || list == NULL) return FALSE;
    Node *toAdd = malloc(sizeof(Node));
    toAdd->data = data;
    toAdd->behind = NULL;

    if(list->length == 0){
        toAdd->infront = NULL;
        list->tail = toAdd;
    }else{
        list->head->behind = toAdd;
        toAdd->infront = list->head;
    }
    list->head = toAdd;
    list->length++;
    return TRUE;
}

bool insertBack(void *data, List *list){
    if(data == NULL || list == NULL) return FALSE;
    Node *toAdd = malloc(sizeof(Node));
    toAdd->data = data;
    toAdd->infront = NULL;

    if(list->length == 0){
        toAdd->behind = NULL;
        list->head = toAdd;
    }else{
        list->tail->infront = toAdd; 
        toAdd->behind = list->tail;
    }
    list->tail = toAdd;
    list->length++;
    return TRUE;
}

bool freeList(List *list){
    if(list == NULL) return FALSE;
    Node *currNode = list->head;
    Node *toFree;
    for(int i = 0; i < list->length; i++){
        list->deleteData(currNode->data);
        toFree = currNode;
        currNode = currNode->infront;

        free(toFree);
    }
    free(list);

    return TRUE;
}

void printList(List *list){
    if(list == NULL) return;

    Node *currNode;
    char *stringHolder;
    currNode = list->head;
    for(int i = 0; i < list->length; i++){
        stringHolder = list->printData(currNode->data); 
        printf("%s", stringHolder);
        free(stringHolder);

        currNode = currNode->infront;
    }
}
