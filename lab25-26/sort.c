#include <stdio.h>
#include <stdlib.h>

#include "dec.h"

void DeckArr(deck *D, int N, int *mas){
    for(int i = 0; i < N; i++){
        mas[i] = PopFront(D);
    }
}

void QuickSort(int* s_arr, int first, int last){
    int i = first, j = last, x = s_arr[(first + last) / 2];
    while (i <= j){
        while (s_arr[i] < x){
            i++;
        }
        while (s_arr[j] > x){
            j--;
        }
        if(i <= j){
            if (s_arr[i] > s_arr[j]) {
                int s_arr1 = s_arr[i];
                s_arr[i] = s_arr[j];
                s_arr[j] = s_arr1;
            }
            i++;
            j--;
        }
    } 
    if (i < last){
        QuickSort(s_arr, i, last);
    }
    if (first < j){
        QuickSort(s_arr, first, j);
    }
}     

void ArrDeck(deck *D, int N, int *mas){
    for(int i = 0; i < N; i++){
        PushBack(D, mas[i]);
    }
}
    

            
