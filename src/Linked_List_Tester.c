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

    printf("================Test 1 passing invalid inputs================\n");

    printf("======================1.1 initList===========================\n");
    assert(initList(NULL, compare, print) == NULL);
    assert(initList(delete, NULL, print) == NULL);
    assert(initList(delete, compare, NULL) == NULL);
    printf("Passed\n");

    printf("===================1.2 insert functions======================\n");
    Data *data = malloc(sizeof(Data));
    assert(insertFront(list, NULL) == FALSE);
    assert(insertFront(NULL, data) == FALSE);
    assert(insertBack(list, NULL) == FALSE);
    assert(insertBack(NULL, data) == FALSE);
    assert(insertAtIndex(list, NULL, 0) == FALSE);
    assert(insertAtIndex(NULL, data, 0) == FALSE);
    free(data);
    printf("Passed\n");

    printf("===================1.3 Remove functions======================\n");
    assert(removeFront(NULL) == NULL);
    assert(removeFront(list) == NULL);
    assert(removeAtIndex(NULL, 0) == NULL);//TODO add testing for invalid indexes in a list with data
    assert(removeAtIndex(list, 0) == NULL);
    assert(removeAtIndex(list, -1) == NULL);
    assert(removeBack(NULL) == NULL);
    assert(removeBack(list) == NULL);
    printf("Passed\n");

    printf("====================1.4 Get functions========================\n");
    assert(getDataFromFront(NULL) == NULL);
    assert(getDataFromFront(list) == NULL);
    assert(getDataFromBack(NULL) == NULL);
    assert(getDataFromBack(list) == NULL);
    assert(getDataFromIndex(NULL, 0) == NULL);
    assert(getDataFromIndex(list, 0) == NULL);
    printf("Passed\n");

    printf("===================1.5 Misc functions========================\n");
    assert(freeList(NULL) == FALSE);
    printf("Passed\n");

    freeList(list);
}