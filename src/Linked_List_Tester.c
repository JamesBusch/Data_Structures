/*********************
 * James Busch
 * 19/04/20
 * 
 * ver 0.02
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

    printf("================Test 1 passing invalid inputs================\n\n");

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
    list = NULL;

    printf("===================Test 2 insert functions===================\n\n");

    printf("======================2.1 insertFront========================\n");
    list = initList(delete, compare, print);
    data = malloc(sizeof(Data));
    data->stuff = 3;
    insertFront(list, data);
    data = NULL;
    assert(((Data*)(list->head->data))->stuff == 3);
    assert(((Data*)(list->tail->data))->stuff == 3);
    assert(list->head->behind == NULL);
    assert(list->head->infront == NULL);
    assert(list->tail->behind == NULL);
    assert(list->tail->infront == NULL);

    data = malloc(sizeof(Data));
    data->stuff = 420;
    insertFront(list, data);
    data = NULL;
    assert(((Data*)(list->head->data))->stuff == 420);
    assert(((Data*)(list->tail->data))->stuff == 3);
    assert(((Data*)(list->head->infront->data))->stuff == 3);
    assert(((Data*)(list->tail->behind->data))->stuff == 420);
    assert(list->head->behind == NULL);
    assert(list->tail->infront == NULL);

    data = malloc(sizeof(Data));
    data->stuff = 42;
    insertFront(list, data);
    data = NULL;
    assert(((Data*)(list->head->data))->stuff == 42);
    assert(((Data*)(list->tail->data))->stuff == 3);
    assert(((Data*)(list->head->infront->data))->stuff == 420);
    assert(((Data*)(list->tail->behind->data))->stuff == 420);
    assert(((Data*)(list->head->infront->infront->data))->stuff == 3);
    assert(((Data*)(list->tail->behind->behind->data))->stuff == 42);
    assert(list->head->behind == NULL);
    assert(list->tail->infront == NULL);
    freeList(list);
    list = NULL;
    printf("Passed\n");

    printf("======================2.2 insertBack=========================\n");
    list = initList(delete, compare, print);
    data = malloc(sizeof(Data));
    data->stuff = 360;
    insertBack(list, data);
    data = NULL;
    assert(((Data*)(list->head->data))->stuff == 360);
    assert(((Data*)(list->tail->data))->stuff == 360);
    assert(list->head->behind == NULL);
    assert(list->head->infront == NULL);
    assert(list->tail->behind == NULL);
    assert(list->tail->infront == NULL);

    data = malloc(sizeof(Data));
    data->stuff = 180;
    insertBack(list, data);
    data = NULL;
    assert(((Data*)(list->head->data))->stuff == 360);
    assert(((Data*)(list->tail->data))->stuff == 180);
    assert(((Data*)(list->head->infront->data))->stuff == 180);
    assert(((Data*)(list->tail->behind->data))->stuff == 360);
    assert(list->head->behind == NULL);
    assert(list->tail->infront == NULL);

    data = malloc(sizeof(Data));
    data->stuff = 90;
    insertBack(list, data);
    data = NULL;
    assert(((Data*)(list->head->data))->stuff == 360);
    assert(((Data*)(list->tail->data))->stuff == 90);
    assert(((Data*)(list->head->infront->data))->stuff == 180);
    assert(((Data*)(list->tail->behind->data))->stuff == 180);
    assert(((Data*)(list->head->infront->infront->data))->stuff == 90);
    assert(((Data*)(list->tail->behind->behind->data))->stuff == 360);
    assert(list->head->behind == NULL);
    assert(list->tail->infront == NULL);
    freeList(list);
    list = NULL;
    printf("Passed\n");

    printf("====================2.3 insertAtIndex========================\n");

}