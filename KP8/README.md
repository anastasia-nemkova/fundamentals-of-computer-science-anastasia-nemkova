# Отчёт по курсовой работе №8 по курсу «Языки и методы программирования»

<b>Студент группы:</b> <ins>М8О-108Б-22, Немкова Анастасия Романовна, № по списку 13</ins>

<b>Контакты e-mail:</b> <ins>nastya.nemkova.04@mail.ru<ins>

<b>Работа выполнена:</b> «13» <ins>мая</ins> <ins>2023</ins>

<b>Преподаватель:</b> <ins>асп. каф.806 Сахарин Никита Александрович</ins>

<b>Отчет сдан</b> «13» <ins>мая</ins> <ins>2023</ins> г., <b>итоговая оценка</b> <ins></ins>

<b>Подпись преподавателя:</b> ___________

## 1. Тема

Линейные списки
  
## 2. Цель работы

Составить и отладить программу на языке Си для обработки линейного списка заданной организации с отображением списка на динамические структуры. Навигацию по списку следует реализовать с применением итераторов. Предусмотреть выполнение одного нестандартного и четырех стандартных действий:
  
  1.	Печать списка.
  
  2.	Вставка нового элемента в список.
  
  3.	Удаление элемента из списка.
  
  4.	Подсчет длины списка.

## 3. Задание (Вариант 13)

**Тип элемента списка:**
  
  Целый
  
**Вид списка:**
  
  Линейный однонаправленный
  
**Нестандартное действие:**
  
  Выполнить попарный обмен значениями элементов списка;


## 4. Оборудование

Процессор: AMD RYZEN 7 5800H 3.20GHz ОП 16 ГБ

HDD: 952 ГБ

Монитор: 3840x2400

## 5. Программное обеспечение

Операционная система семейства: Linux Ubuntu, версия 22.04.1 LTS

Интерпретатор команд: bash, версия 5.0.17(1)

Система программирования: -

Редактор текстов: emacs

Местонахождение и имена файлов программ и данных на домашнем компьютере: \\wsl.localhost\Ubuntu-20.04\home\arnemkova\LABS

## 6. Идея, метод, алгоритм решения задачи
  
`void listClear` - очистка списка;

`void listCreate` - создание списка;

`bool listIsEmpty` - проверка на пустоту;

`ListIterator listIteratorBegin`- ;

`ListIterator listIteratorEnd`;

`int listIteratorInsert` - вставка элемента в список при помощи итератеров;

`int listIteratorRemove` - удаление элемента из списка при помощи итераторов;

`ListIterator *listIteratorNext` - добавление итератора для следующего узла;

`int listIteratorGet` - получение указателя на значение элемента;

`int listIteratorSet` - присваивание значения указателю итератора на узел;

`ListIterator listIteratorIs` - разделение списка по элементам;

`size_t listSize` - получение размера списка;

`void listDestroy` - удаление списка;

`void listPrint`- печать списка;

`int pairWiseSwap` - попарный обмен элементов списка;


## 7. Сценарий выполнения работы

**kp8.h**
```
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

```
**kp8c**
```
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
```

        
**8. Распечатка протокола**

```
arnemkova@LAPTOP-TA2RV74U:~/LABS$ cd kp8
arnemkova@LAPTOP-TA2RV74U:~/LABS/kp8$ gcc kp8.c
arnemkova@LAPTOP-TA2RV74U:~/LABS/kp8$ ./a.out
39 45 18 93 15 12 9 84 63 22
Size: 10
-----
39 45 18 93 15 12 9 63 22
Size: 9
-----
Linked list before calling pairWiseSwap
39 45 18 93 15 12 9 63 22
Linked list after calling pairWiseSwap
45 39 93 18 12 15 63 9 22
```

## 9. Дневник отладки

| **№** | **Лаб.Или Дом.** | **Дата** | **Время** | **Событие** | **Действие по исправлению** | **Примечание** |
| --- | --- | --- | --- | --- | --- | --- |
| **1** | **Дом.** | **09.05.23** | **13:00** | **Выполнение лабораторной работы** | **-** | **-** |

## 10. Замечания автора по существу работы
[Защита div4](https://codeforces.com/contest/1807/submission/198203446)
                                         
[Дорешка div4](https://codeforces.com/contest/1807/submission/206620650)
                                         
[Дорешка div4](https://codeforces.com/contest/1807/submission/206620996)
                                         
[Дорешка div4](https://codeforces.com/contest/1807/submission/206621892)
                                         
## 11. Выводы

В ходе выполнения данной лабораторной работы были изучены линейные однонаправленные списки, отображенные на динамические структуры. Были освоены совершение таких действий над списком, как печать, вставка и удаление элемента, вывод размера списка и навигация при помощи итераторов.

<b>Подпись студента:</b> ___________

