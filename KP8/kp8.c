#include <errno.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include<time.h>

#include "kp8.h"

struct ListNode {
    ListNode *next;
    int data;
};

struct ListIterator{
    ListNode *node;
};

void listCreate(List * const list) {
    list -> head = NULL;
    list -> size = 0;
}

void listClear(List * const list) {
    for (ListNode *node = list->head; node != NULL; node = node->next) {
        free(node);
    }
    *list = (List) { .head = NULL, .size = 0 };
}

void listDestroy(List * const list) {
    listClear(list);
}

ListIterator listIteratorBegin(List * const list) {
    return (ListIterator) { .node = list -> head};
}

ListIterator listIteratorEnd(List * const list) {
    return (ListIterator) { .node = list -> head -> next};
}

int listIteratorInsert(List * const list, ListIterator *it, int value) {
    ListNode *node = malloc(sizeof(ListNode));
    if (node == NULL){
        return errno;
    }
    node->data = value;
    if (it->node == list->head) {
        // Вставка перед головным узлом
        node->next = list->head;
        list->head = node;
    } else {
        ListNode *prev = list->head;
        while (prev != NULL && prev->next != it->node) {
            prev = prev->next;
        }
        if (prev == NULL) {
            free(node);
            return EINVAL;
        }
        node->next = prev->next;
        prev->next = node;
    }
    list->size++;
    return 0;
}

int listIteratorRemove(List * const list, ListIterator *const it) {
    if (list->head == NULL){
        return EINVAL;
    }
    if (it->node == list->head) {
        // Удаление головного узла
        list->head = list->head->next;
        it->node = NULL;
    } else {
        ListNode *prev = list->head;
        while (prev != NULL && prev->next != it->node) {
            prev = prev->next;
        }
        if (prev == NULL)
            return EINVAL;

        prev->next = it->node->next;
        it->node = prev->next;
    }
    list->size--;
    return 0;
}

ListIterator *listIteratorNext(ListIterator * const it) {
    if(it -> node != NULL){
        it -> node = it -> node -> next;
    }
    return it;
}

int listIteratorGet(ListIterator * const it) {
    if(it -> node != NULL){
        return it -> node -> data;
    }
    return 0;
}

int listIteratorSet(ListIterator * const it, int value) {
    if(it -> node != NULL){
        return it -> node -> data = value;
    }
    return 0;
}

ListIterator listIteratorIs(List * const list, const int n) {
    ListIterator tmp = listIteratorBegin(list);
    for (int i = 0; i < n; i++) {
        listIteratorNext(&tmp);
    }
    return tmp;
}

bool listIsEmpty(const List * const list) {
    return list->size == 0;
}

size_t listSize(const List * const list) {
    return list->size;
}

void listPrint(List * const list) {
    if (list->head == NULL) {
        return;
    }
    ListIterator it = listIteratorBegin(list);
    while(it.node != NULL){
        int value = listIteratorGet(&it);
        printf("%d ", value);
        listIteratorNext(&it);
    }
    printf("\n");
}

void swap(int* a, int* b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
 
//Function to pairwise swap elements of a linked list
int pairWiseSwap(List* const list, ListIterator * const it){
    ListIterator tmp = listIteratorBegin(list);
    tmp.node = list -> head;
    while(tmp.node != NULL && tmp.node -> next != NULL){
        swap(&tmp.node ->data, &tmp.node ->next ->data);
        tmp.node = tmp.node -> next -> next;
    }
}


int main(){
    List *list = malloc(sizeof(List));
    listCreate(list);
    ListIterator it = listIteratorBegin(list);

    int index, value;
    srand(time(NULL));
    for(index = 0; index < 10; index++){
        value = rand()%100;
        listIteratorInsert(list, &it, value);
    }
    /*Добавление чисел в список
    int index;
    int value = 5;
    listIteratorInsert(list, &it, value);
    index = 1;
    value = 44;
    it = listIteratorIs(list, index);
    listIteratorInsert(list, &it, value);*/
    listPrint(list);
    printf("Size: %ld\n-----\n", listSize(list));
    
    int num = 7;
    if (0 <= num && num < listSize(list)) {
        it = listIteratorIs(list, num);
        listIteratorRemove(list, &it);
    } else {
        printf("Element with %d number doesn't exists\n", num);
    }
    listPrint(list);
    printf("Size: %ld\n-----\n", listSize(list));

    printf("Linked list before calling pairWiseSwap\n");
    listPrint(list);
    pairWiseSwap(list, &it);
    printf("Linked list after calling pairWiseSwap\n");
    listPrint(list);
    
    listDestroy(list);
    return 0;
}