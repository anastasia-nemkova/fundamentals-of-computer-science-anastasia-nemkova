#include <stdio.h>
#include <stdlib.h>

#include "person.h"

//печать верхней границы таблицы
void printUp(){
    printf ("________________________________________________________________________________________________________\n");
    printf ("| Surname| firstMiddle | Gender | Group | MatAn | LAAG | Discra | Infa | English | Philosophy | Economy |\n");
}

//вывод полного списка студентов
void listPrint(FILE *in){
    Person person;
    while(fread(&person, sizeof(person), 1, in)){
        printf ("|%s  |      %s     |    %c   |  %d  |   %d   |   %d  |    %d   |   %d  |    %d    |      %d     |    %d    |\n",  person.surname, person.firstMiddle, person.gender, person.group, person.markMat, person.markLA, person.markDM, person.markInf, person.markEng, person.markFil, person.markEconom);
        
    }
}

//печать нижней границы таблицы
void printDown(){
    printf ("_________________________________________________________________________________________________________\n");
}

//Сортировка оценок по убыванию
int markSort(int mark[]){
    for(int i = 0; i < 6; i++){
        for(int j = i + 1; j < 6; j++){
            if(mark[i] < mark[j]){
                int t = mark[i];
                mark[i] = mark[j];
                mark[j] = t;
            }
        }
    }
    return mark;
}

//Поиск студенток с одной пятеркой
void listStudents(FILE * in){
    Person person;
    int p;
    int sum = 0;
    printf("Enter the group number\n");
    scanf("%d", &p);
    char *gender = "F";
    while(fread(&person, sizeof(person), 1, in)){
        int mark[] = {person.markMat, person.markLA, person.markDM, person.markInf, person.markEng, person.markFil, person.markEconom};
        markSort(mark);
        if(person.group == p && person.gender == *gender && mark[0] > mark[1]){
        if(sum == 0){
            printUp();
        }
        printf ("|%s  |      %s     |    %c   |  %d  |   %d   |   %d  |    %d   |   %d  |    %d    |      %d     |    %d    |\n",  person.surname, person.firstMiddle, person.gender, person.group, person.markMat, person.markLA, person.markDM, person.markInf, person.markEng, person.markFil, person.markEconom);
        sum++;
        }
    }
    if(sum == 0){
        printf("There are no students having only one 5\n");
    } else{
        printDown();
        printf("Only %d students have exactly one five\n", sum);
    }
    return 0;
}

int main(int argc, char *argv[]){
    if(argc != 3){
        usage();
        return 1;
    }
    FILE *in = fopen(argv[2], "r");
    if(!in){
        perror("Can't open file");
        return 2;
    }
    if(!strcmp(argv[1], "-f")){
        printUp();
        listPrint(in);
        printDown();
    }
    if(!strcmp(argv[1], "-p")){
        listStudents(in);

    }
    fclose(in);
    return 0;
}