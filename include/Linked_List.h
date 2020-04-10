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

typedef enum {TRUE = 1, FALSE = 0} bool;

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
 * @return true if was inserted, false if failed
 ********************/
bool insertFront(void *data, List *list);

/*********************
 * insertBack
 * 
 * This is the function to insert data at the back of the List
 * 
 * @param void *data, data to add too the back of the list
 * @param List *list, the list too add the data too
 * @return true if was inserted, false if failed
 * ******************/
bool insertBack(void *data, List *list);

/*********************
 * getDataFromIndex
 * 
 * This is the function that gets the data from a given index in the list
 * If this is too be used multiple times in a row i.e in a forloop. Please use the 
 * TBD pointer instead as this will make it O(n^2) as it uses a for loop to search
 * 
 * @param List *list, Must exist, must be valid
 * @param int index, Must be in the inclusive range 0-n where n is the length of the given list
 * @return void* to the wanted data
 ********************/
void *getDataFromIndex(List *list, int index);

/*********************
 * freeList
 * 
 * This is the function to free the list. It uses the given free
 * function to free the internal data placed into the list then frees
 * the nodes and finally the list data itself
 * 
 * @param List *list, the list that is wanted to be freed. Must exist and have been created by init list.
 * @return true if list is freed false if error occured
 ********************/
bool freeList(List *list);

/*********************
 * printList
 * 
 * This is the function to print the entire list. It is important that you
 * think of formating. This will only print the given string from the passed print function
 * if you want new lines or spaces you must think about that in the passed print function
 * 
 * @param List *list, list that is wanted to print
 ********************/
void printList(List *list);

#endif
