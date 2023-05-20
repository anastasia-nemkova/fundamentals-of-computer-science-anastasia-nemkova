#ifndef LIST_H
#define LIST_H

#include <stdbool.h>
#include <stddef.h>


typedef struct ListIterator ListIterator;

typedef struct ListNode ListNode;

typedef struct {
    ListNode *head;
    size_t size;
} List;


void listClear(List *list);

void listCreate(List *list);

bool listIsEmpty(const List *list);

ListIterator listIteratorBegin(List *list);

ListIterator listIteratorEnd(List *list);

int listIteratorInsert(List *list, ListIterator *it, int value);

int listIteratorRemove(List *list, ListIterator *it);

ListIterator *listIteratorNext(ListIterator *it);

int listIteratorGet(ListIterator *it);

int listIteratorSet(ListIterator *it, int value);

ListIterator listIteratorIs(List * list, int n);

size_t listSize(const List *list);

void listDestroy(List *list);

void listPrint(List * list);

int pairWiseSwap(List * list, ListIterator *it);

#endif // LIST_H
