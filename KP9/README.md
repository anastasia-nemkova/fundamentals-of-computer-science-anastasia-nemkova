# Отчёт по курсовой работе №9 по курсу «Языки и методы программирования»

<b>Студент группы:</b> <ins>М8О-108Б-22, Немкова Анастасия Романовна, № по списку 13</ins>

<b>Контакты e-mail:</b> <ins>nastya.nemkova.04@mail.ru<ins>

<b>Работа выполнена:</b> «20» <ins>мая</ins> <ins>2023</ins>

<b>Преподаватель:</b> <ins>асп. каф.806 Сахарин Никита Александрович</ins>

<b>Отчет сдан</b> «20» <ins>мая</ins> <ins>2023</ins> г., <b>итоговая оценка</b> <ins></ins>

<b>Подпись преподавателя:</b> ___________

## 1. Тема

Сортировка и поиск
  
## 2. Цель работы

Составить программу на языке Си с использованием процедур и функций для сортировки таблицы заданным методом и двоичного поиска по ключу в таблице.

## 3. Задание (Вариант 13)

**Метод сортировки**
  
  Линейный выбор с подсчетом
  
**Структура таблицы**
  
| **№** | **Тип ключа** | **Размер ключа в байтах** | **Хранение данных и ключей** | **Число элементов таблицы** |
| --- | --- | --- | --- | --- |
| **2** | **Целый** | **4 байта** | **Отдельно** | **10-14** |

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
  
`void getRow` - запись из потока в строку;
  
`int isEqualKeys` - проверка равенства ключей;
  
`int keyCompare` - сравнение ключей;
  
`int binarySearch` - поиск строки по введенному ключу;
  
`void printTable` - печать таблицы;
  
`void tableSort` - сортировка линейным выбором с подсчетом;

## 7. Сценарий выполнения работы

**kp9.h**
```
#ifndef STRUCT_H
#define STRUCT_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_VALUE_SIZE 100
#define MAX_TEXT_SIZE 100

typedef struct{
    int key;
} Key;

typedef struct{
    char val[MAX_VALUE_SIZE];
} Val;

#endif // STRUCT_H
```
**kp9.c**
```
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "kp9.h"

//запись из потока в строку
void getRow(FILE *stream, char *str, const int size){
    int cnt = 0;
    char ch;
    while ((ch = getc(stream)) != '\n' && cnt < size - 1){
        str[cnt++] = ch;
    }
    str[cnt] = '\0';
}

//проверка равенства
int isEqualKeys(const Key k1, const Key k2){
    return k1.key == k2.key;
}

//Сравнение ключей
int keyCompare(const Key k1, const Key k2){
    return k2.key >= k1.key;
}

//Поиск строки по введенному ключу
int binarySearch(const Key *k, const Val *v, const int size, const Key key){
    int left = 0, right = size - 1, mid;
    if (size <= 0){
        return -1;
    }
    while (left < right){
        mid = left + (right - left) / 2;
        if (isEqualKeys(k[mid], key)){
            return mid;
        }else if (keyCompare(k[mid], key)){ 
            left = mid + 1;
        }else{
            right = mid;
        }
    }
    if (isEqualKeys(k[right], key)){
        return right;
    }
    return -1;
}

//печать таблицы
void printTable(const Key *k, const Val *v, const int size){
    int i;

    printf("+--------+------------------------------------------------------------+\n");
    printf("|  Key   |                          String                            |\n");
    printf("+--------+------------------------------------------------------------+\n");

    for (i = 0; i < size; i++)
        printf("|%8d| %s |\n", k[i].key, v[i].val);

    printf("+--------+------------------------------------------------------------+\n");
}

//Сортировка
void tableSort(Key *k, Val *v, const int size){
    int *count = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) {
        count[i] = 0;
    }
    for (int i = 0; i < size - 1; i++) {
        for(int j = i + 1; j < size; j++) {
            if (k[i].key < k[j].key)
                ++count[j];
            else
                ++count[i];
        }
    }
    Val tmpval;
    Key tmpkey;
    int tmp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (count[i] > count[j]) {
                tmp = count[i];
                count[i] = count[j];
                count[j] = tmp;

                tmpkey = k[i];
                k[i] = k[j];
                k[j] = tmpkey;

                tmpval = v[i];
                v[i] = v[j];
                v[j] = tmpval;
            }
        }
    }
    free(count);
}


int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Use: program_name input_file\n");
        return 0;
    }
    Key keys[MAX_TEXT_SIZE];
    Val values[MAX_TEXT_SIZE];
    Key k;
    FILE *file_key = fopen(argv[1], "r");
    if(file_key == NULL){
        printf("Can not open file\n");
        return 1;
    }
    FILE *file_val = fopen(argv[2], "r");
    if(file_val == NULL){
        printf("Can not open file\n");
        return 1;
    }
    int i, cnt, a;
    char ch;
    i = 0;
    while (i < MAX_TEXT_SIZE && fscanf(file_key, "%d", &keys[i].key) == 1){
        fscanf(file_val, "%c", &ch);
        getRow(file_val, values[i].val, sizeof(values[i].val));
        i++;
    }
    fclose(file_key);
    fclose(file_val);
    cnt = i;
    bool tmp = true;
    while (tmp) {
        printf("---------\n1. Print table;\n2. Sort;\n3. Binary search;\n4. Exit.\nEnter the number: ");
        scanf("%d", &a);
        printf("-\n");
        if (a == 1) {
            printf("Table:\n");
            printTable(keys, values, cnt);
        }
        else if (a == 2) {
            printf("Sorted:\n");
            tableSort(keys, values, cnt);
            printTable(keys, values, cnt);
        }
        else if (a == 3) {
            printf("Enter key: ");
            scanf("%d", &k.key);
            i = binarySearch(keys, values, cnt, k);
            if(i){
                printf("String is found: %s\n", values[i].val);
            } else{
                printf("String with such a key was not found\n");
            }
        }
        else if (a == 4) {
            tmp = false;
            printf("Exit\n");
        }
        else {
            printf("Wrong number. Try again.\n");
        }
    }
}
    
```

        
**8. Распечатка протокола**

```
arnemkova@LAPTOP-TA2RV74U:~/LABS/kp9$ gcc kp9.c
arnemkova@LAPTOP-TA2RV74U:~/LABS/kp9$ ./a.out test_key.txt test_val.txt
---------
1. Print table;
2. Sort;
3. Binary search;
4. Exit.
Enter the number: 1
-
Table:
+--------+------------------------------------------------------------+
|  Key   |                          String                            |
+--------+------------------------------------------------------------+
 |    101| ._       __          ____
 |    111|   `\--,-' /`)    _.-'    `-._
 |    131|  /                              `._.'           `---...
 |    141|  |-.   _      ;                        .-----..._______)
 |    151| ,\q/ (q_>'_...                      .-'
 |    161| ==/ ; _.-'~~-             /       ,'
 |    171| ""`-'_,;  `""         ___(       |
 |    191|          `.      //' (    ;`\    `\
 |    201|          / \    ;     `-  /  `-.  /
 |    211|         (  (;   ;     (__/    /  /
 |    221|          \,_)\  ;           ,'  /
 |    231|  .-.          |  |           `--'
 |    241| ("_.)-._     (__,>
 |    121| \_/    ' | /`--,'            `-.     .--....____
 |    181|         \         ; /'/   \      \
+--------+------------------------------------------------------------+
---------
1. Print table;
2. Sort;
3. Binary search;
4. Exit.
Enter the number: 2
-
Sorted:
+--------+------------------------------------------------------------+
|  Key   |                          String                            |
+--------+------------------------------------------------------------+
 |    101| ._       __          ____
 |    111|   `\--,-' /`)    _.-'    `-._
 |    121| \_/    ' | /`--,'            `-.     .--....____
 |    131|  /                              `._.'           `---...
 |    141|  |-.   _      ;                        .-----..._______)
 |    151| ,\q/ (q_>'_...                      .-'
 |    161| ==/ ; _.-'~~-             /       ,'
 |    171| ""`-'_,;  `""         ___(       |
 |    181|         \         ; /'/   \      \
 |    191|          `.      //' (    ;`\    `\
 |    201|          / \    ;     `-  /  `-.  /
 |    211|         (  (;   ;     (__/    /  /
 |    221|          \,_)\  ;           ,'  /
 |    231|  .-.          |  |           `--'
 |    241| ("_.)-._     (__,>
+--------+------------------------------------------------------------+
---------
1. Print table;
2. Sort;
3. Binary search;
4. Exit.
Enter the number: 3
-
Enter key: 151
String is found: ,\q/ (q_>'_...                      .-'
---------
1. Print table;
2. Sort;
3. Binary search;
4. Exit.
Enter the number: 4
-
Exit
```

## 9. Дневник отладки

| **№** | **Лаб.Или Дом.** | **Дата** | **Время** | **Событие** | **Действие по исправлению** | **Примечание** |
| --- | --- | --- | --- | --- | --- | --- |
| **1** | **Дом.** | **20.05.23** | **13:00** | **Выполнение лабораторной работы** | **-** | **-** |

## 10. Замечания автора по существу работы
[Защита div2]()
                                         
[Дорешка div2]()
                                         
## 11. Выводы

В ходе выполнения данной лабораторной работы были изучены .

<b>Подпись студента:</b> ___________


