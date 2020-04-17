/**********************
 * James Busch
 * 17/04/20
 * ver 0.03
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

bool insertAtIndex(void *data, List *list, int index){
    if(data == NULL || list == NULL) return FALSE;
    if(index < 0 || index > list->length) return FALSE;
    if(index == 0){
        return insertFront(data, list);
    }else if(index == list->length){
        return insertBack(data, list);
    }

    Node *toPlace = malloc(sizeof(Node));
    toPlace->data = data;

    //This is to attempt to make the linked list more efficent with larger data by starting either at the
    //Start or end based on if the wanted index is greater than or less than the half way point of the length
    Node *currNode;
    if(index < list->length / 2){//Start at front
        currNode = list->head->infront;//Because the start avoids placements at the start we can skip one and start one after the head
        for(int i = 1; i < index; i++){
            currNode = currNode->infront;
        }
    }else{//start at back
        currNode = list->tail;
        for(int i = list->length - 1; i > index; i--){
            currNode = currNode->behind;
        }
    }
    toPlace->behind = currNode->behind;
    toPlace->infront = currNode;
    currNode->behind->infront = toPlace;
    currNode->behind = toPlace;

    list->length++;
    return TRUE;
}

void *removeFront(List *list){
    if(list == NULL || list->length == 0) return NULL;
    void *dataHolder = list->head->data;

    if(list->length == 1){
        list->tail = NULL;
        free(list->head);
        list->head = NULL;
    }else{
        list->head = list->head->infront;
        free(list->head->behind);
        list->head->behind = NULL;
    }

    list->length--;
    return dataHolder;
}

void *removeBack(List *list){
    if(list == NULL || list->length == 0) return NULL;
    if(list->length == 1) return removeFront(list);//This is so i dont have to re-write code
    void *dataHolder = list->tail->data;

    list->tail = list->tail->behind;
    free(list->tail->infront);
    list->tail->infront = NULL;

    list->length--;
    return dataHolder;
}

void *removeAtIndex(List *list, int index){
    if(list == NULL || list->length == 0) return NULL;
    if(index < 0 || index >= list->length) return NULL;
    if(index == 0) return removeFront(list);
    if(index == list->length - 1) return removeBack(list);

    void *dataHolder;

    Node *currNode;
    if(index < list->length / 2){//Start at front
        currNode = list->head->infront;//Because the start avoids placements at the start we can skip one and start one after the head
        for(int i = 1; i < index; i++){
            currNode = currNode->infront;
        }
    }else{//start at back
        currNode = list->tail;
        for(int i = list->length - 1; i > index; i--){
            currNode = currNode->behind;
        }
    }

    dataHolder = currNode->data;
    currNode->behind->infront = currNode->infront;
    currNode->infront->behind = currNode->behind;
    free(currNode);


    list->length--;
    return dataHolder;
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

void *getDataFromFront(List *list){
    if(list == NULL || list->length < 1) return NULL;

    return list->head->data;
}

void *getDataFromBack(List *list){
    if(list == NULL || list->length < 1) return NULL;

    return list->tail->data;
}

void *getDataFromIndex(List *list, int index){
    if(list == NULL) return NULL;
    if(index >= list->length || index < 0) return NULL;
    if(list->length < 1) return NULL;

    Node *currNode = list->head;

    for(int i = 1; i < index + 1; i++){
        currNode = currNode->infront;
    }

    return currNode->data;
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
