#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stddef.h>

#include "dec.h"


int Empty(deck *D){
    return D -> size == 0;
}

void Init(deck *D){
    D -> first = 0;
    D -> last = 0;
    D -> size = 0;
}

void PushFront(deck *D, int el){
    elem *t=(elem*)malloc(sizeof(elem));
    t -> next = D -> first;
    if(!Empty(D)){
        D -> first -> prev = t;
    }
    D -> first = t;
    D -> first -> value = el;
    if(!D -> size){
        D -> last = t;
    }
    D -> size++;
}

void PushBack(deck *D,int el){
    elem *t=(elem*)malloc(sizeof(elem));
    t -> prev = D -> last;
    if(!Empty(D)){
        D -> last -> next = t;
    }
    D -> last = t;
    D -> last -> value = el;
    if(!D -> size){
        D -> first = t;
    }
    D -> size++;
}

int Size(deck *D){
    return D -> size;
}

int PopBack(deck *D){
    if(Empty(D)){
        printf("Deque is empty\n");
    } else{
        int t = D -> last -> value;
        D -> last = D -> last -> prev;
        D -> last -> next = NULL;
        D -> size--;
        return t;
    }
}

int PopFront(deck *D){
    if(Empty(D)){
        printf("Deque is empty\n");
    } else{
        int t = D -> first -> value;
        D -> first = D -> first -> next;
        D -> size--;
        return t;
    }
}

void PrintDeck(deck *D){
    if(Empty(D)){
        printf("Deque is empty\n");
    } else{
        elem *el = D -> first;
        while(el){
            printf("%d ", el -> value);
            el = el -> next;
        }
    }
}

void Cat(deck *D, deck *D1){
    while(!Empty(D1)){
        PushBack(D, PopFront(D1));
    }
}
