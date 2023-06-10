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