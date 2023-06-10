# Отчёт по курсовой работе №7 по курсу «Языки и методы программирования»

<b>Студент группы:</b> <ins>М8О-108Б-22, Немкова Анастасия Романовна, № по списку 13</ins>

<b>Контакты e-mail:</b> <ins>nastya.nemkova.04@mail.ru<ins>

<b>Работа выполнена:</b> «3» <ins>июня</ins> <ins>2023</ins>

<b>Преподаватель:</b> <ins>асп. каф.806 Сахарин Никита Александрович</ins>

<b>Отчет сдан</b> «3» <ins>июня</ins> <ins>2023</ins> г., <b>итоговая оценка</b> <ins></ins>

<b>Подпись преподавателя:</b> ___________

## 1. Тема

Разряженные матрицы
  
## 2. Цель работы

Составить программу на языке Си с процедурами и/или функциями для обработки прямоугольных разреженных матриц с элементами целого типа, которая:
  
  1.	вводит матрицы различного размера, представленные во входном текстовом файле в обычном формате (по строкам), с одновременным размещением ненулевых элементов в разреженной матрице в соответствии с заданной схемой;
  
  2.	печатает введенные матрицы во внутреннем представлении согласно заданной схеме размещения и в обычном
(естественном) виде;
  
  3.	выполняет необходимые преобразования разреженных матриц (или вычисления над ними) путем обращения к соответствующим процедурам и/или функциям;
  
  4.	печатает результат преобразования (вычисления) согласно заданной схеме размещения и в обычном виде.

## 3. Задание (Вариант 13)

**Вариант схемы размещения матрицы:** 
  
  1. Цепочка ненулевых элементов в векторе А со строчным индексированием (индексы в массиве М равны О, если соответствующая строка матрицы содержит только нули) 
  
**Вариант преобразования**
  
  2. Определить максимальный по модулю элемент матрицы и разделить на него все элементы столбца, в котором он находится.


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

`nodeCol *nodeColCreate()` - создание столбца;

`nodeRow *nodeRowCreate()` - создание ряда;

`void nodeColAdd(nodeRow *nodeRow, nodeCol *newNode)` - добавление элемента в конец;

`void nodeColAddBefore(nodeRow *nodeRow, nodeCol *after_nodeCol, nodeCol *newNode)` - добавление элементов в столбец;

`void nodeRowAdd(Matrix matrix, nodeRow *new_row)` - добавление ряда;

`Matrix matrixCreate(int n, int m)` - создание матрицы;

`void elemSet(Matrix mat, int i, int j, double value)` - вставка элемента;

`double elemGet(Matrix mat, int i, int j)` - получение элемента для вывода;

`void printMatrix(Matrix mat)` - печать матрицы в нормальном виде;

`void printInner(Matrix mat)` - печать матрицы во внутреннем представлении;

`void solution(Matrix mat)` - поиск максимального по модулю элемента и деление всех элементов столца, в котором он находится, на этот элемент;



## 7. Сценарий выполнения работы

**matrix.h**
```
#ifndef __SPMATRIX_H__
#define __SPMATRIX_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct {
    int* data;//индекс начала строки в векторе А
    int size;
    int capacity;
} Mas_M;

typedef struct {
    int column; //номер столбца ненулевого элемента
    float value;//значение ненулевого элемента
    int next_ind;//индекс следующего ненудевого элемента или -1 если в строке нет ненудевых элементов больше
} Elem;

typedef struct {
    Elem* data;
    int size; 
    int capacity;
} VectorA;

VectorA initVecA();
void pushVecA(VectorA* vec, int column, float value, int index);
void pushMasM(Mas_M* mas, int element);
void matrixScan(VectorA* vector, Mas_M* mas, FILE* file);
void printMatrix(VectorA* vec, Mas_M* mas, FILE* file);
void printVec(VectorA* vec);
void printMas(Mas_M* mas);
float elemGet(VectorA* vec, Mas_M* mas, int row, int column);
void elemSet(VectorA* vec, Mas_M* mas, int row, int column, float value);
void divideMax(VectorA* vec, Mas_M* mas);
void freeVectorA(VectorA* vec);
void freeMas(Mas_M* mas);
#endif
```
  
**kp7.c**
  
```
#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

VectorA initVecA() {
    VectorA vec;
    vec.size = 0;
    vec.capacity = 1;
    vec.data = malloc(vec.capacity * sizeof(Elem));
    return vec;
}

void pushVecA(VectorA* vec, int column, float value, int index) {
    if (vec->size == vec->capacity) {
        vec->capacity *= 2;
        vec->data = (Elem*)realloc(vec->data, vec->capacity * sizeof(Elem));
    }
 
    vec->data[vec->size].column = column;
    vec->data[vec->size].value = value;
    vec->data[vec->size].next_ind = index;
    vec->size++;   
}

void pushMasM(Mas_M* mas, int element) {
    if (mas->size == mas->capacity) {
        mas->capacity *= 2;
        mas->data = (int*)realloc(mas->data, mas->capacity * sizeof(int));
    }
  
    mas->data[mas->size] = element;
    mas->size++;   
}

void matrixScan(VectorA* vector, Mas_M* mas, FILE* file) {
    int n, m;
    fscanf(file, "%d%d", &n, &m); 
    int capacity = n;
    mas->data = (int*)malloc(capacity * sizeof(int));
    mas->size = 0;
    mas->capacity = capacity;
    int nz = 0;
    for (int i = 0; i < n; i++) {
        int check = 1;
        int last_index = -1;
        for (int j = 0; j < m; j++) {
            float num;
            fscanf(file, "%f", &num);
            if (num != 0) {
                if (check) {
                    mas->data[i] = nz;
                    mas->size++;
                    if (mas->size == mas->capacity) {
                        mas->capacity *= 2;
                        mas->data = (int*)realloc(mas->data, mas->capacity * sizeof(int));
                    }
                    check = 0;
                }
                int column_num = j;
                float value_num = num;
                int index_num = -1;
                pushVecA(vector, column_num, value_num, index_num);
                nz++;
                if (last_index != -1) {
                    vector->data[last_index].next_ind = vector->size - 1;
                }
                last_index = vector->size - 1;
            }
        }
        if (nz == 0 && last_index != -1) {
            vector->data[last_index].next_ind = -1;
        }
        if (check) {
            mas->data[i] = -1;
            mas->size++;
            if (mas->size == mas->capacity) {
                mas->capacity *= 2;
                mas->data = (int*)realloc(mas->data, mas->capacity * sizeof(int));
            }
        }
    }
    fseek(file, 0, SEEK_SET);
}


void printMatrix(VectorA* vec, Mas_M* mas, FILE* file) {
    int n, m;
    fscanf(file, "%d%d", &n, &m); 
    for (int i = 0; i < n; i++) {
        int index_m = -1;
        if (mas->data[i] != -1) {
            index_m = mas->data[i];
        }
        int count = 0;
        for (int r = index_m; r != -1; r = vec->data[r].next_ind) {
            count++;
        }
        int xind = index_m;
        for (int j = 0; j < m; j++) {
            if (xind != -1 && vec->data[xind].column == j) {
                printf("%.2f ", vec->data[xind].value);
                xind = vec->data[xind].next_ind;
            } else {
                printf("0.00 ");
            }
        }
        printf("\n");
    }
}

void printVec(VectorA* vec) {
    if (vec->size == 0) {
        printf("Empty\n");
    } else {
        printf("A: ");
        for (int i = 0; i < vec->size; i++) {
            printf("(%d;%lf;%d) ", vec->data[i].column, vec->data[i].value, vec->data[i].next_ind);
        }
        printf("\n");
    }
}

void printMas(Mas_M* mas) {
    if (mas->size == 0) {
        printf("Empty\n");
    } else {
        printf("M: ( ");
        for (int i = 0; i < mas->size; i++) {
            printf("%d ", mas->data[i]);
        }
        printf(")\n");
    }
}

float elemGet(VectorA* vec, Mas_M* mas, int row, int column) {
    int start = mas->data[row];
    for (int i = start; i != -1; i = vec->data[i].next_ind) {
        if (vec->data[i].column == column) {
            return vec->data[i].value;
        }
    }
    return 0.0f;
}

void elemSet(VectorA* vec, Mas_M* mas, int row, int column, float value) {
    int start = mas->data[row];
    int prev_ind = -1;
    int curr_ind = start;
    while (curr_ind != -1 && vec->data[curr_ind].column < column) {
        prev_ind = curr_ind;
        curr_ind = vec->data[curr_ind].next_ind;
    }

    if (curr_ind != -1 && vec->data[curr_ind].column == column) {
        if (value != 0.0f) {
            vec->data[curr_ind].value = value;
        } else {
            if (prev_ind != -1) {
                vec->data[prev_ind].next_ind = vec->data[curr_ind].next_ind;
            } else {
                mas->data[row] = vec->data[curr_ind].next_ind;
            }
            vec->data[curr_ind].next_ind = -1;
        }
    } else {
        if (value != 0.0f) {
            int new_ind = vec->size;
            pushVecA(vec, column, value, -1);
            if (prev_ind != -1) {
                vec->data[prev_ind].next_ind = new_ind;
            } else {
                mas->data[row] = new_ind;
            }
        }
    }
}

void divideMax(VectorA* vec, Mas_M* mas) {
    int maxIndex = 0;
    int targetColumn = 0;
    int count = 0;
    int prevTargetColumn = -1;
    int prevPrevTargetColumn = -1;

    // Находим столбец с максимальным по модулю элементом
    for (int i = 0; i < vec->size; i++) {
        float value = vec->data[i].value;
        if (fabs(value) > fabs(vec->data[maxIndex].value)) {
            maxIndex = i;
            targetColumn = vec->data[i].column;
        }
    }

    for (int i = 0; i < vec->size; i++) {
        if (vec->data[i].value == vec->data[maxIndex].value) {
            count++;
            prevPrevTargetColumn = prevTargetColumn;
            prevTargetColumn = vec->data[i].column;
        }
    }
    
    if (count > 1 && prevTargetColumn > prevPrevTargetColumn) {
        targetColumn = prevPrevTargetColumn;
    } else if(count > 1 && prevTargetColumn < prevPrevTargetColumn){
        targetColumn = prevTargetColumn;
    }

    float maxValue = fabs(vec->data[maxIndex].value);

    // Деление всех элементов столбца на максимальный элемент
    for (int i = 0; i < vec->size; i++) {
        if (vec->data[i].column == targetColumn) {
            vec->data[i].value /= maxValue;
        }
    }
    printf("Max elem: %.1f\n", maxValue);
}

void freeVectorA(VectorA* vec) {
    if (vec->data) {
        free(vec->data);
    }
    vec->size = 0;
    vec->capacity = 0;
}

void freeMas(Mas_M* mas) {
    if (mas->data) {
        free(mas->data);
    }
    mas->size = 0;
    mas->capacity = 0;
}

int main(int argc, char* argv[]) {
 
    FILE *in = fopen(argv[1], "r");
    if (!in) {
        printf("Error: can't open file.\n");
        exit(1);
    }
    
    VectorA vec = initVecA();
    Mas_M mas;
    matrixScan(&vec, &mas, in);

    printf("Matrix in normal form:\n");
    printMatrix(&vec, &mas, in);
               
    printf("Matrix according to the representation scheme:\n");
    printVec(&vec);
    printMas(&mas);

    printf("Dividing a matrix column\n");
    divideMax(&vec, &mas);

    fseek(in, 0, SEEK_SET);
    printMatrix(&vec, &mas, in);

    printf("Get element: %.2f\n", elemGet(&vec, &mas, 1, 3));
    elemSet(&vec, &mas, 2, 2, -42.0);

    fseek(in, 0, SEEK_SET);
    printMatrix(&vec, &mas, in);

    freeVectorA(&vec);
    freeMas(&mas);
    fclose(in);
    return 0;
}

```

        
**8. Распечатка протокола**

```
arnemkova@LAPTOP-TA2RV74U:~/LABS/kp7.1$ gcc matrix.c
arnemkova@LAPTOP-TA2RV74U:~/LABS/kp7.1$ valgrind --leak-check=full ./a.out test.txt
==2652== Memcheck, a memory error detector
==2652== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==2652== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
==2652== Command: ./a.out test.txt
==2652==
Matrix in normal form:
1.00 0.00 0.00 0.00 0.00 0.00
0.00 0.00 0.00 5.00 0.00 0.00
2.00 0.00 0.00 0.00 0.00 3.00
0.00 0.00 2.00 0.00 2.00 0.00
3.00 4.00 5.00 0.00 0.00 0.00
0.00 0.00 0.00 0.00 0.00 0.00
Matrix according to the representation scheme:
A: (0;1.000000;-1) (3;5.000000;-1) (0;2.000000;3) (5;3.000000;-1) (2;2.000000;5) (4;2.000000;-1) (0;3.000000;7) (1;4.000000;8) (2;5.000000;-1)
M: ( 0 1 2 4 6 -1 )
Dividing a matrix column
Max elem: 5.0
1.00 0.00 0.00 0.00 0.00 0.00
0.00 0.00 0.00 5.00 0.00 0.00
2.00 0.00 0.00 0.00 0.00 3.00
0.00 0.00 0.40 0.00 2.00 0.00
3.00 4.00 1.00 0.00 0.00 0.00
0.00 0.00 0.00 0.00 0.00 0.00
Get element: 5.00
1.00 0.00 0.00 0.00 0.00 0.00
0.00 0.00 0.00 5.00 0.00 0.00
2.00 0.00 -42.00 0.00 0.00 0.00
0.00 0.00 0.40 0.00 2.00 0.00
3.00 4.00 1.00 0.00 0.00 0.00
0.00 0.00 0.00 0.00 0.00 0.00
==2652==
==2652== HEAP SUMMARY:
==2652==     in use at exit: 0 bytes in 0 blocks
==2652==   total heap usage: 10 allocs, 10 frees, 6,036 bytes allocated
==2652==
==2652== All heap blocks were freed -- no leaks are possible
==2652==
==2652== For lists of detected and suppressed errors, rerun with: -s
==2652== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

## 9. Дневник отладки

| **№** | **Лаб.Или Дом.** | **Дата** | **Время** | **Событие** | **Действие по исправлению** | **Примечание** |
| --- | --- | --- | --- | --- | --- | --- |
| **1** | **Дом.** | **03.06.23** | **13:00** | **Выполнение лабораторной работы** | **-** | **-** |

## 10. Замечания автора по существу работы
[Защита Олимпрога](https://mai2022.contest.codeforces.com/group/Ej1bTQMkro/contest/427395/submission/202883146)
                                         
[Дорешка](https://mai2022.contest.codeforces.com/group/Ej1bTQMkro/contest/427395/submission/202880504)
                                         
## 11. Выводы

В ходе выполнения данной лабораторной работы были освоены преобразования над разряженными матрицами. Также были изучены векторы, отображение матриц на цепочку векторов.

<b>Подпись студента:</b> ___________


