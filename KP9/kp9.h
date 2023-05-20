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