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
