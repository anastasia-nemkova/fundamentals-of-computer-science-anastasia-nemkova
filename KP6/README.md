# Отчёт по курсовой работе №6 по курсу «Языки и методы программирования»

<b>Студент группы:</b> <ins>М8О-108Б-22, Немкова Анастасия Романовна, № по списку 13</ins>

<b>Контакты e-mail:</b> <ins>nastya.nemkova.04@mail.ru<ins>

<b>Работа выполнена:</b> «13» <ins>мая</ins> <ins>2023</ins>

<b>Преподаватель:</b> <ins>асп. каф.806 Сахарин Никита Александрович</ins>

<b>Отчет сдан</b> «13» <ins>мая</ins> <ins>2023</ins> г., <b>итоговая оценка</b> <ins></ins>

<b>Подпись преподавателя:</b> ___________

## 1. Тема

Обработка последовательной файловой структуры на СИ
  
## 2. Цель работы

Разработать последовательную структуру данных для представления простейшей базы данных на файлах в СП Си в соответствии с заданным вариантом. Составить программу генерации внешнего нетекстового файла заданной структуры, содержащего представительный набор записей (15-20). Распечатать содержимое сгенерированного файла в виде таблицы и выполнить над ним заданное действие для 2-3 значений параметров запроса р и распечатать результат. 
Действие по выборке данных из файла оформить в виде отделыюй программы с параметрами запроса, вводимыми из стандартного входного текстового файла, или получаемыми из командной строки UNIX. Параметры задаются с помощью ключей -f (распечатка файла) или -р <parameter> (параметры конкретного варианта задания). Получение параметров из командной строки производится с помощью стандартных библиотечных функций argc и argv.

## 3. Задание (Вариант 13)

Информация об успеваемости студентов данной группы по всем предметам: фамилия, инициалы, пол, номер группы, отметки по экзаменам и зачетам.
Выяснить, сколько студенток группы р имеют ровно одну пятёрку.

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
  
`readPerson()` - считывает данные из исходного файла;
  
`printUp()` - печать верхней границы таблицы;
  
`listPrint()` - вывод полного списка студентов;
  
`printDown()` - печать нижней границы таблицы;
  
`markSort()` - cортировка оценок по убыванию;
  
`listStudents()` - поиск студенток с одной пятеркой

## 7. Сценарий выполнения работы

**person.h**
```
#ifndef PERSON_H
#define PERSON_H

#define LINE_SIZE (40U)

typedef struct{
    char surname[LINE_SIZE];
    char firstMiddle[LINE_SIZE];
    char gender;
    int group;
    int markMat;
    int markLA;
    int markDM;
    int markInf;
    int markEng;
    int markFil;
    int markEconom;
} Person;

void usage(){
    printf("Usage: program filename\nF");
}
#endif //_PERSON_H_
```
**person_dump.c**
```
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "person.h"

int readPerson(FILE *in, Person * const person){
    return fscanf(in, "%s\t%s\t%c\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n", person -> surname, person -> firstMiddle, &person -> gender, &person -> group, &person -> markMat, &person -> markLA, &person -> markDM, &person -> markInf, &person -> markEng, &person -> markFil, &person -> markEconom) == 11;
}

int main(int argc, char *argv[]){
    if(argc != 3){
        usage();
        return 1;
    }
    Person person;
    FILE *in = fopen(argv[2], "r");
    if(!in){
        perror("Can't open file\n");
        return 2;
    }
    FILE *out = fopen(argv[1], "w");
    if(!out){
        perror("Can't open file\n");
        return 2;
    }
    
    while(readPerson(in, &person)){
        fwrite(&person, sizeof(person), 1, out); 
    }
    fclose(in);
    fclose(out);
    return 0;
}
```

**kp6.c**
```
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
```
        
**8. Распечатка протокола**

```
arnemkova@LAPTOP-TA2RV74U:~/LABS/kp6$ gcc -w person_dump.c
arnemkova@LAPTOP-TA2RV74U:~/LABS/kp6$ ./a.out res.bin person_list.txt
arnemkova@LAPTOP-TA2RV74U:~/LABS/kp6$ gcc -w kp6.c
arnemkova@LAPTOP-TA2RV74U:~/LABS/kp6$ ./a.out res.bin
Usage: program filename
Farnemkova@LAPTOP-TA2RV74U:~/LABS/kp6$ ./a.out -f res.bin
________________________________________________________________________________________________________
| Surname| firstMiddle | Gender | Group | MatAn | LAAG | Discra | Infa | English | Philosophy | Economy |
|Fyghau  |      UI     |    F   |  101  |   5   |   5  |    4   |   4  |    5    |      4     |    5    |
|Hhagih  |      TY     |    M   |  102  |   5   |   5  |    5   |   5  |    3    |      4     |    5    |
|Vsdfik  |      NY     |    F   |  101  |   4   |   4  |    5   |   4  |    4    |      4     |    4    |
|Rfwaoa  |      FT     |    F   |  101  |   3   |   2  |    4   |   5  |    4    |      4     |    4    |
|Fqjfiq  |      GY     |    F   |  102  |   3   |   5  |    5   |   3  |    4    |      4     |    5    |
|Ywihnv  |      FG     |    F   |  102  |   5   |   5  |    5   |   4  |    5    |      5     |    5    |
|Kravch  |      AR     |    M   |  134  |   3   |   5  |    4   |   2  |    2    |      5     |    2    |
|Iliina  |      AP     |    F   |  109  |   2   |   2  |    2   |   2  |    5    |      5     |    4    |
|Tetrad  |      RK     |    F   |  134  |   3   |   4  |    5   |   4  |    5    |      4     |    3    |
|Smirnv  |      SS     |    M   |  102  |   2   |   2  |    4   |   3  |    5    |      4     |    3    |
|Vasyit  |      AA     |    F   |  105  |   5   |   5  |    4   |   4  |    4    |      5     |    5    |
|Bylkov  |      KA     |    F   |  108  |   5   |   4  |    4   |   4  |    5    |      5     |    5    |
|Ssooss  |      OK     |    M   |  105  |   4   |   2  |    3   |   5  |    4    |      4     |    4    |
|Ashoka  |      ER     |    F   |  134  |   3   |   5  |    4   |   4  |    4    |      4     |    4    |
|Vintva  |      TY     |    F   |  109  |   4   |   4  |    4   |   4  |    4    |      4     |    5    |
|Ruitda  |      HO     |    F   |  105  |   3   |   3  |    3   |   5  |    4    |      4     |    3    |
|Ramnki  |      MM     |    F   |  108  |   2   |   4  |    2   |   5  |    3    |      3     |    3    |
|Rechka  |      MM     |    F   |  108  |   5   |   4  |    4   |   4  |    4    |      3     |    2    |
|Voikav  |      SM     |    M   |  105  |   2   |   4  |    5   |   5  |    5    |      4     |    3    |
|Avitov  |      CK     |    M   |  134  |   5   |   4  |    5   |   5  |    5    |      5     |    5    |
|Deleta  |      EC     |    F   |  134  |   4   |   4  |    2   |   4  |    3    |      5     |    2    |
|Insert  |      UJ     |    M   |  109  |   2   |   3  |    4   |   5  |    2    |      4     |    4    |
|Occhko  |      MP     |    F   |  102  |   2   |   3  |    2   |   3  |    2    |      5     |    3    |
|Milkaf  |      SH     |    F   |  101  |   4   |   4  |    5   |   5  |    5    |      4     |    3    |
|Shnuyr  |      TZ     |    M   |  105  |   3   |   5  |    3   |   3  |    3    |      3     |    4    |
_________________________________________________________________________________________________________
arnemkova@LAPTOP-TA2RV74U:~/LABS/kp6$ ./a.out -p res.bin
Enter the group number
101
________________________________________________________________________________________________________
| Surname| firstMiddle | Gender | Group | MatAn | LAAG | Discra | Infa | English | Philosophy | Economy |
|Vsdfik  |      NY     |    F   |  101  |   4   |   4  |    5   |   4  |    4    |      4     |    4    |
|Rfwaoa  |      FT     |    F   |  101  |   3   |   2  |    4   |   5  |    4    |      4     |    4    |
_________________________________________________________________________________________________________
Only 2 students have exactly one five
arnemkova@LAPTOP-TA2RV74U:~/LABS/kp6$ ./a.out -p res.bin
Enter the group number
102
________________________________________________________________________________________________________
| Surname| firstMiddle | Gender | Group | MatAn | LAAG | Discra | Infa | English | Philosophy | Economy |
|Occhko  |      MP     |    F   |  102  |   2   |   3  |    2   |   3  |    2    |      5     |    3    |
_________________________________________________________________________________________________________
Only 1 students have exactly one five
arnemkova@LAPTOP-TA2RV74U:~/LABS/kp6$ ./a.out -p res.bin
Enter the group number
134
________________________________________________________________________________________________________
| Surname| firstMiddle | Gender | Group | MatAn | LAAG | Discra | Infa | English | Philosophy | Economy |
|Ashoka  |      ER     |    F   |  134  |   3   |   5  |    4   |   4  |    4    |      4     |    4    |
|Deleta  |      EC     |    F   |  134  |   4   |   4  |    2   |   4  |    3    |      5     |    2    |
_________________________________________________________________________________________________________
Only 2 students have exactly one five
arnemkova@LAPTOP-TA2RV74U:~/LABS/kp6$ ./a.out -p res.bin
Enter the group number
109
There are no students having only one 5
```

## 9. Дневник отладки

| **№** | **Лаб.Или Дом.** | **Дата** | **Время** | **Событие** | **Действие по исправлению** | **Примечание** |
| --- | --- | --- | --- | --- | --- | --- |
| **1** | **Дом.** | **09.05.23** | **13:00** | **Выполнение лабораторной работы** | **-** | **-** |

## 10. Замечания автора по существу работы
[Защита div4](https://codeforces.com/contest/1829/submission/204854650)

[Защита div4](https://codeforces.com/contest/1829/submission/204841140)

[Защита div4](https://codeforces.com/contest/1829/submission/204839293)
  
[Дорешка div4](https://codeforces.com/contest/1829/submission/205703437)
  
[Дорешка div4](https://codeforces.com/contest/1829/submission/205695101)

## 11. Выводы

В ходе выполнения данной лабораторной работы была освоена работа с текстовыми файлами, генерация бинарного файла из текстового. Были изучены функции стандартной библиотеки stdio.h, такие как fscanf, fwrite, freadstrcmp. и 

<b>Подпись студента:</b> ___________
