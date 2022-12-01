# Отчёт по лабораторной работе №12 по курсу «Фундаментальная информатика»

<b>Студент группы:</b> <ins>М8О-108Б-22, Немкова Анастасия Романовна, № по списку 14</ins>

<b>Контакты e-mail:</b> <ins>nastya.nemkova.04@mail.ru<ins>

<b>Работа выполнена:</b> «18» <ins>ноября</ins> <ins>2022</ins>

<b>Преподаватель:</b> <ins>асп. каф.806 Сахарин Никита Александрович</ins>

<b>Отчет сдан</b> «26» <ins>ноябрь</ins> <ins>2022</ins> г., <b>итоговая оценка</b> <ins>5

<b>Подпись преподавателя:</b> ___________

## 1. Тема

Техника работы с целыми числами. Системы счисления.

## 2. Цель работы

Составить программу на языке Си в целом типе данных, которая для любых допустимых и корректно записанных чисел этого типа в десятичном изображенииб поступающих на ствндартный ввод программыб выполняет указанное в задании действие над их значениями

## 3. Задание

Проверить, все ли цифры в смежных разрадях различны.

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

Вводим число. Сравниваем цифры в соседних разрядах этого числа. Для этого дерём остаток от деления на 10 введённого числа, делим данное число на 10 и ещё раз берём остаток, затем сравниваем получившиеся остатки и продолжаем до тех пор, по введённое число не будет равно 0.  Если все соседние цифры не равны, то число состоит из различных цифр

## 7. Сценарий выполнения работы


Код программы:

```
#include <stdio.h>

int main (){
    long N;
    scanf("%ld", &N);
	  int d,k;
	  int c = 0;
	  k = N % 10;
	  while (N != 0){
	      N = N / 10;
		    d = N % 10;
		    if (d == k){
		        c = 1;
		        break;
		    } 
		k = d;	
	}
	if (c) printf("NO\n");
	else printf("DIFFERENT\n");
	return 0;
}
  
```

## 8. Распечатка протокола

```
anastasia@anastasia-VirtualBox:~$ gcc laba12.c
anastasia@anastasia-VirtualBox:~$ ./a.out
10113
NO
anastasia@anastasia-VirtualBox:~$ ./a.out
15373228
NO
anastasia@anastasia-VirtualBox:~$ ./a.out
1233647
NO
anastasia@anastasia-VirtualBox:~$ ./a.out
2131364986
DIFFERENT
anastasia@anastasia-VirtualBox:~$ ./a.out
2574935
DIFFERENT
anastasia@anastasia-VirtualBox:~$ ./a.out
36475855231
NO
anastasia@anastasia-VirtualBox:~$ ./a.out
2345678987654
DIFFERENT
anastasia@anastasia-VirtualBox:~$ ./a.out
464956453423877
NO

```

## 9. Дневник отладки

| № | Лаб.ИлиДом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| --- | --- | --- | --- | --- | --- | --- |
| 1 | Дом. | 12.11.22 | 14:03 | Написание программы на Си по работе с целыми числами | - | - |

## 10. Замечания автора по существу работы

Программа для проверки различности смежных разрядов числа, написанная с использованием getchar, switch и case
```
#include <stdio.h>

typedef enum {
    LIMITATIONS,
    NUMBER1,
    NUMBER2,
    COMPARISON,
    ENTER,
}Step;


int process() {
    int d, k;
    int c = 0;
    int g = 0;
    Step step = LIMITATIONS;
    char N = getchar();
    while (N != EOF) {
        switch(step) {
            case LIMITATIONS:
                if(N != ' ') {
                    step = NUMBER1;
                }
                if(N == '\n') {
                    break;
                }
                if(N == ' ') {
                    step = ENTER;
                    continue;  
                }
            case NUMBER1:
                d = N - '0';
                step = NUMBER2;
            case NUMBER2:
                N = getchar();
                if (N != ' ') {
                    k = N - '0';
                step = COMPARISON;
                }
                if(N == ' ') {
                    step = ENTER;
                    continue;
                }
            case COMPARISON:
                if(d == k) {
                    ++g;
                }
                step = LIMITATIONS;       
                continue;
            case ENTER:
              goto newword;
          }
          
        newword: break;
        
    }
    return g;
       
}

void result() {
    for (char N = getchar(); N != EOF; N = getchar()) {
        if(N!= ' ') {
            int g = process();
            if(g > 0) {
                printf("NO\n");
            }
            if(g == 0) {
                printf("DIFFERENT\n");
            }
        }
    }        
}
 
 int main() {
     result();
     return 0;
 }
 
 ```

## 11. Выводы

В ходе выполнения данной лабораторной работы были приобретены навыки для работы с целочисленным типом данных на языке Си. Были освоены функция getchar,оператор множественного выбора switch, case, конструкция цикла с предусловием while, условный оператор if и математематические операторы. Также было изучено поразрядное сревнение цифр целого десятичного числа.

<b>Подпись студента:</b> ___________
