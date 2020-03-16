/**********************
 * James Busch
 * 08/03/20
 * ver 0.01
 * 
 * This is the include for the Linked_List API.
 * If you wish too use any of this for school projects
 * please sight this code to avoid any issues that might arise
 **********************/
#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <stdio.h>
#include <stdlib.h>

/*********************
 * This is the node data for the linked list
 * It is a doubly linked list and requires a pointer
 * for data, this is for a universal use amoung data instead 
 * of having to remake the list for different uses
 ********************/
typedef struct Node{
    struct Node *infront;
    struct Node *behind;
    void *data;
}Node;

/*********************
 * This is all the data for the list. It includes 
 * the functions needed to compare, delete and print the given data
 *********************/
typedef struct List{
    Node *head;
    Node *tail;
    int length;

    void (*deleteData)(void* toDelete);
    int (*compareData)(const void* first,const void* second);
    char* (*printData)(void* toPrint);
}List;

List *initList(void (*delete)(void *toDelete), int(*compare)(const void *, const void *), char* (*print)(void*));
void insertFront(void *data, List *list);

#endif
