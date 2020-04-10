/*********************
 * James Busch
 * 24/03/20
 * 
 * This is the tester for the Data_Structures API.
 * As I build each data structure I will push the current tester
 * to show iterative testing.
 * ******************/

#include <stdio.h>
#include <stdlib.h>
#include "Linked_List.h"

void delete(void *toDelete);
int compare(const void *dataOne, const void *dataTwo);
char *print(void *data);

typedef struct Data{
    int stuff;
}Data;

int main(){
    List *testList = initList(&delete, &compare, &print);
    Data *data;
    for(int i = 0; i < 2; i++){
        data = malloc(sizeof(Data));
        data->stuff = i;
        insertFront(data, testList);

        data = NULL;
    }

    for(int i = 3; i < 6; i++){
        data = malloc(sizeof(Data));
        data->stuff = i;
        insertBack(data, testList);
    }
    printList(testList);

    printf("===Data at index 0: %d\n", ((Data*)(getDataFromIndex(testList, 0)))->stuff);
    printf("===Data at index 2: %d\n", ((Data*)(getDataFromIndex(testList, 2)))->stuff);

    freeList(testList);




    return 0;
}

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