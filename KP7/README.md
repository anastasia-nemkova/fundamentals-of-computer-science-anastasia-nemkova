# Отчёт по курсовой работе №7 по курсу «Языки и методы программирования»

<b>Студент группы:</b> <ins>М8О-108Б-22, Немкова Анастасия Романовна, № по списку 13</ins>

<b>Контакты e-mail:</b> <ins>nastya.nemkova.04@mail.ru<ins>

<b>Работа выполнена:</b> «20» <ins>мая</ins> <ins>2023</ins>

<b>Преподаватель:</b> <ins>асп. каф.806 Сахарин Никита Александрович</ins>

<b>Отчет сдан</b> «20» <ins>мая</ins> <ins>2023</ins> г., <b>итоговая оценка</b> <ins></ins>

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
#ifndef MATRIX_H
#define MATRIX_H

typedef struct nodeCol nodeCol;
typedef struct nodeRow nodeRow;
typedef struct matrix *Matrix;

struct nodeCol{
	int column;
	double element;
	struct nodeCol *next;
};

struct nodeRow{
	nodeCol *beginRow;
	struct nodeRow *next;
};

struct matrix{
	int n;
	int m;
	int entries;
	nodeRow *headRow;
} ;

nodeCol *nodeColCreate();

nodeRow *nodeRowCreate();

void nodeColAdd(nodeRow *nodeRow, nodeCol *newNode);

void nodeColAddBefore(nodeRow *nodeRow, nodeCol *after_nodeCol, nodeCol *newNode);

void nodeRowAdd(Matrix matrix, nodeRow *new_row);

Matrix matrixCreate(int n, int m);

void elemSet(Matrix mat, int i, int j, double value);

double elemGet(Matrix mat, int i, int j);

void printMatrix(Matrix mat);

void printInner(Matrix mat);

void solution(Matrix mat);


#endif // MATRIX_H
```
  
**kp7.c**
  
```
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h> 

#include "matrix.h"


//создаём столбец
nodeCol *nodeColCreate(){
	nodeCol *newNode = (nodeCol *) malloc(sizeof(nodeCol));
	if(newNode == NULL){
		return 0;
	}
	newNode->next = NULL;
	return newNode;
}

//создаём ряд 
nodeRow *nodeRowCreate(){
	nodeRow *newNode = (nodeRow *) malloc(sizeof(nodeRow));
	if(newNode == NULL){
		return 0;
	}
	newNode->beginRow = NULL;
	newNode->next = NULL;
}

//добавляем элемент в конец ( тк последний элемент Null, то мы должны послднему элементу передать ссылку на новый элемент, а новому передаём ссылку на Null)
void nodeColAdd(nodeRow *nodeRow, nodeCol *newNode){
	nodeCol *tmp = nodeRow->beginRow;
	if(tmp == NULL){
		nodeRow->beginRow = newNode;
		newNode->next = NULL;
		return;
	}
	while(tmp->next){
		tmp = tmp->next;
	}
	tmp->next = newNode;
	newNode->next = NULL;
}

//просто добавляем элементы в столбец
void nodeColAddBefore(nodeRow *nodeRow, nodeCol *after_nodeCol, nodeCol *newNode){
	nodeCol *tmp = nodeRow->beginRow;
	if(nodeRow->beginRow == after_nodeCol){
		newNode->next = nodeRow->beginRow;
		nodeRow->beginRow = newNode;
	}
	while(tmp && (tmp->next != after_nodeCol)){
		tmp = tmp->next;
	}
	if(tmp){
		newNode->next = tmp->next;
		tmp->next = newNode;
	}
}

//добавление ряда
void nodeRowAdd(Matrix matrix, nodeRow *new_row){
	nodeRow *tmp = matrix->headRow;
	if(tmp == NULL){
		matrix->headRow = new_row;
		new_row->next = NULL;
		new_row->beginRow = NULL;
		return;
	}
	while(tmp->next){
		tmp = tmp->next;
	}
	tmp->next = new_row;
	new_row->next = NULL;
	new_row->beginRow = NULL;
}

//создаём матрицу 
Matrix matrixCreate(int n, int m){
	Matrix matrix = (Matrix) malloc(sizeof(Matrix));
	if(matrix == NULL){
		return 0;
	}
	matrix->n = n;
	matrix->m = m;
	matrix->entries = 0;
	nodeRow *nodeRow;
	for(int i=0; i<n; ++i){
		nodeRow = nodeRowCreate();
		nodeRowAdd(matrix, nodeRow);
		nodeRow = nodeRow->next;
	}
	return matrix;
}

//вставка элемента
void elemSet(Matrix mat, int i, int j, double value){
	nodeCol *newNode;
	if(value != 0){
		mat->entries++; //увеличиваем количество элементов
		nodeRow *nodeRow = mat->headRow;
		for(; i>1; --i){
			nodeRow = nodeRow->next;
		}
		nodeCol *nodeCol = nodeRow->beginRow;
		bool insert_last = true;//пусть столбец последний
		while(nodeCol){
			if(nodeCol->column < j){ //если не дошли до нужного столбца
				nodeCol = nodeCol->next; //переходим к следующему 
			} else {
				newNode = nodeColCreate();
				nodeColAddBefore(nodeRow, nodeCol, newNode);
				newNode->column = j;
				newNode->element = value;
				insert_last = false; //столбец не последний
				break;
			}

		}
		if(insert_last){ 
			nodeCol = nodeColCreate();
			nodeColAdd(nodeRow, nodeCol);
			nodeCol->column = j;
			nodeCol->element = value;
		}
	}
}
//получение элемента для вывода
double elemGet(Matrix mat, int i, int j){
	if(mat->headRow == NULL){
		return 0;
	}
	nodeRow *row = mat->headRow;
	while(i>1){
		row = row->next;
		--i;
	}
	if(row == NULL){
		return 0;
	}
	else {
		for(nodeCol *h = row->beginRow; h; h=h->next){
			if(h->column == j){
				return h->element;
			}
		}
		return 0;
	}
}
//вывод матрицы
void printMatrix(Matrix mat){
	for(int i = 1; i <= mat->n; ++i){
        for(int j = 1; j <= mat->m; ++j){
			double number = elemGet(mat, i, j);
			printf("%.2lf\t", number);
		}
		printf("\n");
	}
	printf("\n");
}

//вывод внутреннего представления
void printInner(Matrix mat){
	for(int i = 1; i <= mat->n; ++i){
		printf("%d  ||", i);
        for(int j = 1; j <= mat->m; ++j){
			double number = elemGet(mat, i, j);
			if (number != 0)
			{
				printf("  %d  |  %.1lf  ||", j, number);
			}
		}
		printf("  |  ");
	}
	printf("\n");
}

//находим максимальный по модулю элемент и делим на него элементы столбца, в котором он находится
void solution(Matrix mat) {
  int max_row = -1;
  int max_col = -1;
  double max_value = 0.0;

  for (int i = 1; i <= mat->n; ++i) {
    for (int j = 1; j <= mat->m; ++j) {
      double number = elemGet(mat, i, j);
      if (fabs(number) > fabs(max_value)) {
        max_row = i;
        max_col = j;
        max_value = number;
      }
    }
  }

  if (max_row != -1 && max_col != -1) {
    int target_col = max_col;

    for (int j = 1; j <= mat->m; ++j) {
      double number = elemGet(mat, max_row, j);
      if (j != max_col && fabs(number) == fabs(max_value)) {
        target_col = j;
      }
    }

    // Делим элементы столбца на максимальный по модулю элемент
    for (int i = 1; i <= mat->n; ++i) {
      double number = elemGet(mat, i, target_col);
      number /= fabs(max_value);
      elemSet(mat, i, target_col, number);
    }
  }

  printMatrix(mat);
}



int main(int argc, char *argv[]) {
	if(argc != 2){
        printf("ERROR\n");
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if(!file){
        perror("Can't open file");
        return 2;
    }
	int row, col, chose;
  	double value;
	fscanf(file, "%d %d", &row, &col);
	Matrix mat = matrixCreate(row, col);
  	for (int i = 1; i <= row; i++) {
    	for (int j = 1; j <= col; j++) {
      		double value;
      		fscanf(file, "%lf", &value);
      		elemSet(mat, i, j, value);
    	}
  	}

  	fclose(file);
	int g = 1;
	while(g == 1){
		printf("Select action:\n1)Print matrix in normal form\n2)Print matrix in inner representation\n3)Perform task on matrix\n4)Exit\n");
		scanf("%d", &chose);
		switch (chose){
			case 1:
				if(mat == NULL){
					printf("Matrix is empty\n");
				} else {
					printf("Matrix in normal form:\n");
					printMatrix(mat);
				}
				break;
			case 2:
				if(mat == NULL){
					printf("Matrix is empty\n");
				} else {
					printf("Matrix in inner representation:\n");
					printInner(mat);
				}
				break;
			case 3:
				solution(mat);
				break;
			case 4:
				g = 0;

		}
	}	
}
```

        
**8. Распечатка протокола**

```

```

## 9. Дневник отладки

| **№** | **Лаб.Или Дом.** | **Дата** | **Время** | **Событие** | **Действие по исправлению** | **Примечание** |
| --- | --- | --- | --- | --- | --- | --- |
| **1** | **Дом.** | **03.06.23** | **13:00** | **Выполнение лабораторной работы** | **-** | **-** |

## 10. Замечания автора по существу работы
[Защита Олиппрога](https://mai2022.contest.codeforces.com/group/Ej1bTQMkro/contest/427395/submission/202883146)
                                         
[Дорешка](https://mai2022.contest.codeforces.com/group/Ej1bTQMkro/contest/427395/submission/202880504)
                                         
## 11. Выводы

В ходе выполнения данной лабораторной работы были освоены преобразования над разряженными матрицами. Также были изучены векторы, отображение матриц на цепочку векторов.

<b>Подпись студента:</b> ___________


