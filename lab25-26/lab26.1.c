#include <stdio.h>
#include <stdlib.h>
#include "dec.h"

void init(Deck * const deck){
    deck -> head = -1;
    deck -> tail = -1;
    deck -> size = 0;
    return;
}

bool isEmpty(Deck * const deck){
     return deck -> size == 0;
}

size_t deckSize(Deck * const deck){
    return deck -> size;
}

bool pushFront(Deck * const deck, Elem el){
    if (!isEmpty(deck)){
        if(--(deck -> head) < 0){
            deck -> head = N - 1;
        }
    } else {
        deck -> tail = deck -> head = 0;
    }
    deck -> data[deck -> head] = el;
    deck -> size++;
    return true;

}

bool pushBack(Deck * const deck, Elem el){
    if (!isEmpty(deck)){
        if(++(deck -> tail) < 0){
            deck -> tail = 0;
        }
    } else {
        deck -> tail = deck -> head = 0;
    }
    deck -> data[deck -> tail] = el;
    deck -> size++;
    return true;
}

int popFront(Deck * const deck){
    ptrdiff_t index = deck -> head;
    if(isEmpty(deck)){
        printf("Deque is empty\n");
    }
    if(deck -> size == 1){
        deck -> tail = deck -> head = -1;
    } else{
        if(++(deck -> head) == N){
            deck -> head = 0;
        }
    }
    deck -> size--;
    return deck -> data[index];
}

int popBack(Deck * const deck){
    ptrdiff_t index = deck -> tail;
    if(isEmpty(deck)){
        printf("Deque is empty\n");
    }
    if(deck -> size == 1){
        deck -> tail = deck -> head = -1;
    } else{
        if(--(deck -> tail) < 0){
            deck -> tail = N - 1;
        }
    }
    deck -> size--;
    return deck -> data[index];
}
    

void printDeck(Deck * const deck){
    int i = deck -> head; 
    while(i > deck -> tail && i != N && deck -> data[i] != 0){
        printf("%d ", deck -> data[i]);
        i++;
    }
    if (i == N){
        i = 0;
    }
    for(i; i <= deck -> tail; i++){
        printf("%d ", deck -> data[i]);
    }
}

int deckTop(Deck * const deck){
    if(isEmpty(deck)){
        printf("Deque is empty\n");
    } else{
        return deck -> data[deck -> head];
    }
    return -1;
}

void deckCat(Deck * const deck1, Deck * const deck2){
    while(!isEmpty(deck2)){
        pushBack(deck1, popFront(deck2));
    }
}

void quickSort(Deck * const deck){
    Deck *deck1, *deck2;
    deck1 = (Deck*)malloc(N*sizeof(deck));
    deck2 = (Deck*)malloc(N*sizeof(deck));  
    Elem V, V1;
    if (!isEmpty(deck)){
        init(deck1);
        init(deck2);
        V = popFront(deck);
        while (!isEmpty(deck)) {
            if (deckTop(deck) < V)
                pushBack(deck1, popFront(deck));
            else
                pushBack(deck2, popFront(deck));
        }
        quickSort(deck1);
        quickSort(deck2);
        pushBack(deck1, V);
        deckCat(deck1, deck2);
        deckCat(deck, deck1);
    }
}

int main(){
    Deck *deck;
    deck = (Deck*)malloc(N*sizeof(deck));
    int flag = 1;
    int ans, n, el;
    printf("Select an action:\n"
    "1. Create deq\n"
    "2. Print deq\n"
    "3. Size of deq\n"
    "4. Push front\n"
    "5. Push back\n"
    "6. Delete first element of deq\n"
    "7. Delete last element of deq\n"
    "8. Sorting deq\n"
    "9. Clear deq\n"
    "10. Concatenation two deq\n" 
    "0. Exit\n");
    while(flag == 1){
        printf("Enter the number: ");
        scanf("%d", &ans);
        switch(ans){
            case 0:
                flag = 0;
                break;
                
            case 1:
                init(deck);
                printf("Enter the number of elements\n");
                scanf("%d", &n);
                for(int i = 0; i < n; i++){
                    scanf("%d", &el);
                    pushBack(deck, el);
                }	
                break;
                
            case 2:
                printDeck(deck);
                printf("\n");
                break;
                
            case 3:
                printf("Size: %ld\n", deckSize(deck));
                break;
                
            case 4:
                printf("Enter the element\n");
                scanf("%d", &el);
                pushFront(deck, el);
                break;
                
            case 5:
                printf("Enter the element\n");
                scanf("%d", &el);
                pushBack(deck, el);
                break;
                
            case 6:
                printf("Delet: %d\n", popFront(deck));
                break;
                
            case 7:
                printf("Delet: %d\n", popBack(deck));
                break;
                
            case 8:
                quickSort(deck);
                break;
                
            case 9:
                init(deck);
                break;
                
            case 10:
                if(isEmpty(deck)){
                    printf("Enter the number of elements first deq\n");
                    scanf("%d", &n);
                    init(deck);
                    for(int i = 0; i < n; i ++){
                        scanf("%d", &el);
                        pushBack(deck, el);
                    }
                } 
                printf("Enter the number of elements second deq\n");
                int n1;
                scanf("%d", &n1);
                Deck *deck1;
                deck1 = (Deck*)malloc(sizeof(Deck));
                init(deck1);
                for(int i = 0; i < n1; i++){
                    scanf("%d", &el);
                    pushBack(deck1, el);
                }
                deckCat(deck, deck1);
                break;
        }
    }
}
                
