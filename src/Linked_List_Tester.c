/*********************
 * James Busch
 * 17/04/20
 * 
 * This is the full tester for the linked list API
 ********************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Linked_List.h"
#include "Linked_List_Tester.h"

typedef struct Data{
    int stuff;
}Data;

void delete(void *toDelete){
    free(toDelete);
    return;
}

int compare(const void *dataOne, const void *dataTwo){
    return ((Data*)dataOne)->stuff - ((Data*)dataTwo)->stuff;
}

char *print(void *data){
    char *holder = malloc(sizeof(int) * 14);
    holder[0] = '\0';
    sprintf(holder, "%d\n", ((Data*)data)->stuff);
    return holder;
}

void LinkedListTest(){
    List *list = initList(delete, compare, print);
}