# Отчёт по лабораторной работе №13 по курсу «Фундаментальная информатика»

<b>Студент группы:</b> <ins>М8О-108Б-22, Немкова Анастасия Романовна, № по списку 14</ins>

<b>Контакты e-mail:</b> <ins>nastya.nemkova.04@mail.ru<ins>

<b>Работа выполнена:</b> «08» <ins>декабря</ins> <ins>2022</ins>

<b>Преподаватель:</b> <ins>асп. каф.806 Сахарин Никита Александрович</ins>

<b>Отчет сдан</b> «09» <ins>декабря</ins> <ins>2022</ins> г., <b>итоговая оценка</b> <ins>

<b>Подпись преподавателя:</b> ___________

## 1. Тема

Множества

## 2. Цель работы

Составить программу проверки характеристик введенных последовательностей слов и печати развернутого ответа в соответствии с вариантом задания.

## 3. Задание

Есть ли согласная, не входящая ни в одно слово.

## 4. Оборудование

Процессор: AMDRYZEN 7 5800H 3.20GHz ОП 16 ГБ

НDD: 952 ГБ

Монитор: 3840 × 2400

## 5. Программное обеспечение

Операционная система семейства: Linux Ubuntu, версия 22.04.1 LTS

Интерпретатор команд: bash, версия 5.0.17(1)

Система программирования: gcc

Редактор текстов: emacs


## 6. Идея, метод, алгоритм решения задачи

1. Создаем функцию is_separator, определяющую является ли входной символ разделителем. 
2. Создаем функцию letter_to_int, которая проверяет входной символ, является ли он буквой.
3. Создаем функцию letter_to_set, которая вычисляет значение функции letter_to_int по входному значению и возвращает это значение в виде множества.
4. В основной функции check_letters составляем множество согласных, равное объединению множеств, состоящих из одной согласной. Считываем один символ из введенных слов, если он не равен EOF, то мы объединяем set all_letters, равный нулю, с представленным в виде множества считанным символом. Если он равен EOF, то мы смотрим, равно ли пересечение полученного множества all_letters с множеством всех согласных множеству всех согласных. Если равно, то нет согласных, невходящих ни в одно слово; в противоположном случае - есть.


## 7. Сценарий выполнения работы

```:src/lab13.c
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef unsigned long long set;

bool is_separator(int sym) {
    return (sym == ' ' || sym == '\t' || sym == '\n');
}

int letter_to_int(int sym) {
    if (sym >= 'a' && sym <= 'z')
        return sym - 'a';
    if (sym >= 'A' && sym <= 'Z')
        return sym - 'A';
    else
      return -1;
}

set letter_to_set(int sym) {
    int ind = letter_to_int(sym);
    return (1U) << ind;
}

void check_letters() {
    int c;
    set all_letters = 0;
    set consonant_letters = letter_to_set('B') | letter_to_set('C') | letter_to_set('D') | letter_to_set('F') | letter_to_set('G') | letter_to_set('H') | letter_to_set('J') | letter_to_set('K') | letter_to_set('L') | letter_to_set('M') | letter_to_set('N') | letter_to_set('P') | letter_to_set('Q') | letter_to_set('R') | letter_to_set('S') | letter_to_set('T') | letter_to_set('V') | letter_to_set('W') | letter_to_set('X');
    while (true) {
        c = getchar();
        if (is_separator(c)) {
            continue;
        } else if (c == EOF) {
            if (((all_letters & consonant_letters) == consonant_letters)) { 
                printf("NO \n");
            } else { 
                printf("YES\n");
            }
            break;
        } else {
            all_letters = all_letters | letter_to_set(c);
        }
    }
}

int main() {
    check_letters();
    return 0;
}
  
```

## 8. Распечатка протокола

```
anastasia@anastasia-VirtualBox:~$ gcc lab13.c
anastasia@anastasia-VirtualBox:~$ ./a.out
RRU yrechjew rioejvnb bxnbhxgrf12 /jwef.fjefjew4
YES
anastasia@anastasia-VirtualBox:~$ ./a.out
fghjkloiuytredfghjukjhv vfghjchyfyhg hcvbnbbnfddsippkk,,mvcsqqweazxxcv bmnm.,j.l;ol[o]gpdieuywteredyutiosxjhsgsafaqgbzbxncmc
NO 
anastasia@anastasia-VirtualBox:~$ ./a.out
weyrucuwb cqwuiuqREEWDF hhwjwuedgcSDF qwertbcvxnzm uyecg
YES
anastasia@anastasia-VirtualBox:~$ ./a.out
 uwhcu iuznwuqdup cggw.,.kzpiedzp\pw[p  wuiuijkwq idwj
YES
anastasia@anastasia-VirtualBox:~$ ./a.out
uyehcede sdxbxsvxdweiuweuipejlf sbdgh
YES
anastasia@anastasia-VirtualBox:~$ ./a.out
0
YES
anastasia@anastasia-VirtualBox:~$ ./a.out
rty
YES

```

## 9. Дневник отладки

| № | Лаб.ИлиДом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| --- | --- | --- | --- | --- | --- | --- |
| 1 | Дом. | 08.12.22 | 14:03 | Написание программы на Си по работе с множествами | - | - |

## 10. Замечания автора по существу работы


## 11. Выводы

В ходе выполнения данной лабораторной работы была составлена программа на Си, определящая наличие или отсутствие согласной невходящей ни в одно из введенных слов. Были приобретены навыки по работе с множествами. Было изучено написание set и побитовые операции над множествами. 

<b>Подпись студента:</b> ___________
