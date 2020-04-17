/*********************
 * James Busch
 * 17/04/20
 * ver 0.01
 * 
 * This is the full tester for the linked list API
 ********************/
#ifndef LINKED_LIST_TESTER_H_
#define LINKED_LIST_TESTER_H_

typedef struct Data{
    int stuff;
}Data;

void delete(void *toDelete);
int compare(const void *dataOne, const void *dataTwo);
char *print(void *data);

void LinkedListTest();

#endif

