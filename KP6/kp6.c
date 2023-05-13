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

int markFind(int mark[]){
    int sum = 0;
    for(int i = 0; i < 7; i++){
        if(mark[i] == 5){
            ++sum;
        }
    }
    return sum;
}

//Поиск студенток с одной пятеркой
void listStudents(FILE * in, int p){
    Person person;
    int sum = 0;
    char *gender = "F";
    while(fread(&person, sizeof(person), 1, in)){
        int mark[] = {person.markMat, person.markLA, person.markDM, person.markInf, person.markEng, person.markFil, person.markEconom};
        
        if(person.group == p && person.gender == *gender && markFind(mark) == 1 ){
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
    int p = atoi(argv[1]);
    if(p){
        listStudents(in, p);

    }
    fclose(in);
    return 0;
}