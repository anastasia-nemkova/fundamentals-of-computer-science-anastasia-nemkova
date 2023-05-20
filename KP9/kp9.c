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

//поиск строки по введенному ключу
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
    
