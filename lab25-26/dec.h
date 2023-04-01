#ifndef DECK_H
#define DECK_H

typedef struct Elem elem;
typedef struct Deck deck;

struct Elem{
    int value; //знaчение эл.
    elem *prev; //указ. на пред.
    elem *next; //указ. на след.
};

struct Deck{
    int size; //кол-во эл.
    elem *first; //указ. на первый
    elem *last; //указ. на последний
};


int Empty(deck *D);
void Init(deck *D);
void PushFront(deck *D, int el);
void PushBack(deck *D,int el);
int Size(deck *D);
int PopBack(deck *D);
int PopFront(deck *D);
void PrintDeck(deck *D);
void Cat(deck *D, deck *D1);

#endif // DECK_H
