# Отчёт по лабораторной работе №25-26 по курсу «Языки и методы программирования»

<b>Студент группы:</b> <ins>М8О-108Б-22, Немкова Анастасия Романовна, № по списку 13</ins>

<b>Контакты e-mail:</b> <ins>nastya.nemkova.04@mail.ru<ins>

<b>Работа выполнена:</b> «01» <ins>апреля</ins> <ins>2023</ins>

<b>Преподаватель:</b> <ins>асп. каф.806 Сахарин Никита Александрович</ins>

<b>Отчет сдан</b> «01» <ins>мапреля</ins> <ins>2023</ins> г., <b>итоговая оценка</b> <ins></ins>

<b>Подпись преподавателя:</b> ___________

## 1. Тема

Автоматизация сборки программ модульной структуры на Си с использованием утилиты make. Абстрактные типы данных. Рекурсия

## 2. Цель работы

Составить Makefile для модульной программы и сам программный модуль, сортирующий экземпляр указанного абстрактного типа данных заданным методом, используя только операции, импортированные из модуля UUDT

## 3. Задание (Вариант 13)

Конкатенация двух деков с реализацией быстрой сортировки Хоара, создание Makefile для модульной программы
  
**Указания**
1) Дек отображается на массив;
2) В программе по возможности должна использоваться рекурсия;
3) Метод сортировки реализовать с использованием указанной вспомогательной процедуры(быстрая сортировка Хоара);
4) Использование итераторов для навигации по сериальным структурам.

## 4. Оборудование

Процессор: AMD RYZEN 7 5800H 3.20GHz ОП 16 ГБ

HDD: 952 ГБ

Монитор: 3840x2400

## 5. Программное обеспечение

Операционная система семейства: Linux Ubuntu, версия 22.04.1 LTS

Интерпретатор команд: bash, версия 5.0.17(1)

Система программирования: -

Редактор текстов: emacs

Местонахождение и имена файлов программ и данных на домашнем компьютере: /home/anastasia

## 6. Идея, метод, алгоритм решения задачи

1. Создаем Makefile для модульной программы;

2. В `dec.h` объявляем имена всех функций, находящихся в `dec.c`;

3. В `dec.c` необходимо проинклудить заголовочный файл `"dec.h"` и проинциализировать все функции:

	`int Empty()` - проверяет дек на пустоту;
	
	`void Init()` - создает дек с нулевыми значениями;
	
	`void PushFront()` - добавляет элемент в начало дека;
	
	`void PushBack()` - добавляет элементв конец дека;
	
	`int Size()` - возвращает размер дека;
	
	`int PopBack()` - удаляет один элемент с конца;
	
	`int PopFront()`- удаляет один элемент с начала;
	
	`void PrintDeck()` - вывод дек;
	
	`void Cat()` - конкатенация двух деков;
	
4. В `sort.h` объявляем имена всех функций, находящихся в `sort.c`;

5. В `sort.c` инициализируем функции:

	`void DeckArr()` - преобразование дека в массив;
	
	`void QuickSort()` - быстрая сортировка Хоара;
	
	`void ArrDeck()` - преобразование массива в дек;
	
6. В `lab26.c` прописываем итераторы для навигации по функциям.

## 7. Сценарий выполнения работы

**Makefile**
```
CC = gcc
CFLAGS = -g 
OBJ = lab26.o dec.o sort.o
PROG = program

build: lab26.o dec.o sort.o
		$(CC) $(CFLAGS) -o $(PROG) $(OBJ)
        
lab26.o: lab26.c
		$(CC) $(CFLAGS) -c lab26.c
        
dec.o: dec.c dec.h
		$(CC) $(CFLAGS) -c dec.c

sort.o: sort.c sort.h
	    $(CC) $(CFLAGS) -c sort.c

clean:
	rm $(PROG) $(OBJ)
```
**sort.h**
  ```#ifndef SORT_H
#define SORT_H

#include "dec.h"

void DeckArr(deck *D, int N, int *mas);
void QuickSort(int* s_arr, int first, int last);
void ArrDeck(deck *D, int N, int *mas);

#endif // SORT_H
```
**sort.c**
  ```
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
```
**dec.h**
```
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
int Top(deck *D);

#endif // DECK_H
```
**dec.c**
```
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

int Top(deck *D){
    if (Empty(D)){
        printf("Deque is empty\n");
    } else{
        return D -> first -> value;
    }
}
```
**lab26.c**
```
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
```
        
**8. Распечатка протокола**

```
anastasia@anastasia-VirtualBox:~/lab25-26$ make
gcc -g  -c lab26.c
gcc -g  -c dec.c
gcc -g  -c sort.c
gcc -g  -o program lab26.o dec.o sort.o
anastasia@anastasia-VirtualBox:~/lab25-26$ ./a.out
Select an action:
1. Create deq
2. Print deq
3. Size of deq
4. Push front
5. Push back
6. Delete first element of deq
7. Delete last element of deq
8. Sorting deq
9. Clear deq
10. Concatenation two deq
0. Exit
Enter the number: 1
Enter the number of elements
5
2 7 1 5 3

Select an action:
1. Create deq
2. Print deq
3. Size of deq
4. Push front
5. Push back
6. Delete first element of deq
7. Delete last element of deq
8. Sorting deq
9. Clear deq
10. Concatenation two deq
0. Exit
Enter the number: 3
Size: 5
Select an action:
1. Create deq
2. Print deq
3. Size of deq
4. Push front
5. Push back
6. Delete first element of deq
7. Delete last element of deq
8. Sorting deq
9. Clear deq
10. Concatenation two deq
0. Exit
Enter the number: 6
Delet: 2
Select an action:
1. Create deq
2. Print deq
3. Size of deq
4. Push front
5. Push back
6. Delete first element of deq
7. Delete last element of deq
8. Sorting deq
9. Clear deq
10. Concatenation two deq
0. Exit
Enter the number: 2
7 1 5 3 
Select an action:
1. Create deq
2. Print deq
3. Size of deq
4. Push front
5. Push back
6. Delete first element of deq
7. Delete last element of deq
8. Sorting deq
9. Clear deq
10. Concatenation two deq
0. Exit
Enter the number: 8
Select an action:
1. Create deq
2. Print deq
3. Size of deq
4. Push front
5. Push back
6. Delete first element of deq
7. Delete last element of deq
8. Sorting deq
9. Clear deq
10. Concatenation two deq
0. Exit
Enter the number: 2
1 3 5 7 
Select an action:
1. Create deq
2. Print deq
3. Size of deq
4. Push front
5. Push back
6. Delete first element of deq
7. Delete last element of deq
8. Sorting deq
9. Clear deq
10. Concatenation two deq
0. Exit
Enter the number: 10
Enter the number of elements second deq
4
2 7 1 9

Select an action:
1. Create deq
2. Print deq
3. Size of deq
4. Push front
5. Push back
6. Delete first element of deq
7. Delete last element of deq
8. Sorting deq
9. Clear deq
10. Concatenation two deq
0. Exit
Enter the number: 2
1 3 5 7 2 7 1 9 
Select an action:
1. Create deq
2. Print deq
3. Size of deq
4. Push front
5. Push back
6. Delete first element of deq
7. Delete last element of deq
8. Sorting deq
9. Clear deq
10. Concatenation two deq
0. Exit
Enter the number: 8
Select an action:
1. Create deq
2. Print deq
3. Size of deq
4. Push front
5. Push back
6. Delete first element of deq
7. Delete last element of deq
8. Sorting deq
9. Clear deq
10. Concatenation two deq
0. Exit
Enter the number: 2
1 1 2 3 5 7 7 9 
Select an action:
1. Create deq
2. Print deq
3. Size of deq
4. Push front
5. Push back
6. Delete first element of deq
7. Delete last element of deq
8. Sorting deq
9. Clear deq
10. Concatenation two deq
0. Exit
Enter the number: 0
anastasia@anastasia-VirtualBox:~/lab25-26$ make clean
rm program lab26.o dec.o sort.o

```

## 9. Дневник отладки

| **№** | **Лаб.Или Дом.** | **Дата** | **Время** | **Событие** | **Действие по исправлению** | **Примечание** |
| --- | --- | --- | --- | --- | --- | --- |
| **1** | **Дом.** | **01.04.23** | **13:00** | **Выполнение лабораторной работы** | **-** | **-** |

## 10. Замечания автора по существу работы

**Защита с Олимпроги**

1. https://mai2022.contest.codeforces.com/group/Ej1bTQMkro/contest/427392/submission/199850155

2. https://mai2022.contest.codeforces.com/group/Ej1bTQMkro/contest/427392/submission/199845505


## 11. Выводы

Благодаря данной лабораторной работе было освоено создание модульной программы и реализация абстрактных типов данных. Была изучена утилита make и создание Makefile. Были получены навыки по работе с двусторонней очередью(создание, добавлениие элемента в начале/конце, удаление элемента),реализации конкатенации двух деков и быстрой сортировки Хоара.

<b>Подпись студента:</b> ___________
