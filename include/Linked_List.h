/*********************
 * James Busch
 * 24/03/20
 * ver 0.01
 * 
 * This is the include for the Linked_List API.
 * If you wish too use any of this for school projects
 * please sight this code to avoid any issues that might arise
 ********************/
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
 ********************/
typedef struct List{
    Node *head;
    Node *tail;
    int length;

    void (*deleteData)(void* toDelete);
    int (*compareData)(const void* first,const void* second);
    char* (*printData)(void* toPrint);
}List;

/*********************
 * initList
 * 
 * This is the function to create a list so that all operations are possible. 
 * ONLY USE THIS TO CREATE A LIST, do not create your own pointer as it will not work
 * 
 * @param void* toDelete, This is the function to delete the data held inside each node
 * @param void* compare, This is the function to compare 2 peices of data incase sorting is ever needed
 * @param void* print, This is the function to print the data held inside each node
 * @return List* to the created List
 ********************/
List *initList(void (*delete)(void *toDelete), int(*compare)(const void *, const void *), char* (*print)(void*));

/*********************
 * insertFront
 * 
 * This is the function to insert data at the front of the List
 * 
 * @param void *data, data to add too the front of the list
 * @param List *list, the list too add the data too
 ********************/
void insertFront(void *data, List *list);

/*********************
 * insertBack
 * 
 * This is the function to insert data at the back of the List
 * 
 * @param void *data, data to add too the back of the list
 * @param List *list, the list too add the data too
 * ******************/
void insertBack(void *data, List *list);

#endif
