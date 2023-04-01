#include <stdio.h>
#include <stdlib.h>
#include "dec.h"
#include "sort.h"

  
int main(){
    int flag = 1, ans = 11, n;
    int N, mas[N];
    deck *D;
    D = (deck*)malloc(sizeof(deck));
    int el;
    while(flag == 1){
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
        "0. Exit\n"
        "Enter the number: ");
        scanf("%d", &ans);
        switch(ans){
            case 0:
                flag = 0;
                break;
                
            case 1:
                Init(D);
                printf("Enter the number of elements\n");
                scanf("%d", &n);
                Init(D);
                for(int i = 0; i < n; i ++){
                    scanf("%d", &el);
                    PushBack(D, el);
                }
                printf("\n");
                break;
                
            case 2:
                PrintDeck(D);
                printf("\n");
                break;
                
            case 3:
                printf("Size: %d\n", Size(D));
                break;
                
            case 4:
                printf("Enter the element\n");
                scanf("%d\n", &el);
                PushFront(D, el);
                break;
                
            case 5:
                printf("Enter the element\n");
                scanf("%d\n", &el);
                PushBack(D, el);
                break;
                
            case 6:
                printf("Delet: %d\n", PopFront(D));
                break;
            
            case 7:
                printf("Delet: %d\n", PopBack(D));
                break;
                
            case 8:
                N = Size(D);
                mas[N];
                DeckArr(D, N, mas);
                QuickSort(mas, 0, N-1); 
                ArrDeck(D, N, mas);
                break;
                
            case 9:
                Init(D);
                break;
                
            case 10:
                if(Empty(D)){
                    printf("Enter the number of elements first deq\n");
                    scanf("%d", &n);
                    Init(D);
                    for(int i = 0; i < n; i ++){
                        scanf("%d", &el);
                        PushBack(D, el);
                    }
                } 
                printf("Enter the number of elements second deq\n");
                int n1;
                scanf("%d", &n1);
                deck *D1;
                D1 = (deck*)malloc(sizeof(deck));
                Init(D1);
                for(int i = 0; i < n1; i++){
                    scanf("%d", &el);
                    PushBack(D1, el);
                }
                Cat(D, D1);
                printf("\n");
                break;
               
        }
    }
}  


