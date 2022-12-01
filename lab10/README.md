# Отчёт по лабораторной работе №10 по курсу «Фундаментальная информатика»

<b>Студент группы:</b> <ins>М8О-108Б-22, Немкова Анастасия Романовна, № по списку 14</ins>

<b>Контакты e-mail:</b> <ins>nastya.nemkova.04@mail.ru<ins>

<b>Работа выполнена:</b> «24» <ins>октября</ins> <ins>2022</ins>

<b>Преподаватель:</b> <ins>асп. каф.806 Сахарин Никита Александрович</ins>

<b>Отчет сдан</b> «26» <ins>ноябрь</ins> <ins>2022</ins> г., <b>итоговая оценка</b> <ins> 5

<b>Подпись преподавателя:</b> ___________

## 1. Тема

Отладчик системы программирования ОС UNIX

## 2. Цель работы

Освоить отладку простейших программ с помощью gdb на языке С

## 3. Задание

Отладить ошибку в простейшей программе

## 4. Оборудование

Процессор: AMDRYZEN 7 5800H 3.20GHz ОП 16 ГБ

НDD: 952 ГБ

Монитор: 3840 × 2400

## 5. Программное обеспечение

Операционная система семейства: LinuxUbuntu, версия 22.04.1 LTS

Интерпретатор команд: bash, версия 5.0.17(1)

Система программирования: gcc

Редактор текстов: emacs

Утилиты операционной системы: gdb

## 6. Идея, метод, алгоритм решения задачи

Написать простейшую программу на С, скомпилировать её с флагом -g, запустить отладчик gdb и проделать основные команды ( ``list``, ``run``, ``break``, ``next``, ``stop``, ``setargs``, ``showargs``, ``setvar``, ``backtrace`` ) по отладке программы.

## 7. Сценарий выполнения работы

Скомпилируем программу и используем команды ``help``, ``run``, ``print``, ``setvar``, ``next``, ``step``, ``continue``, ``break``, ``bt``, ``list``, ``setargs`` для её отладки при помощи gdb

Код программы:

```
#include <stdio.h>

#include <math.h>

int main(void){

   double a, b, c, x1, x2, D;

   scanf("%lf%lf%lf", &a, &b, &c);

   D = b*b - 4*a*c;

   if( D < 0 ){

      printf("No rootsn");}

   else if( D == 0 ){

      x1 = -b/(2*a);

      printf("One root: %lf\n", x1);

   }

   else {

      x1 = (-b - sqrt(D)) / (2*a);

      x2 = (-b + sqrt(D)) / (2*a);

      printf("Two roots: %lf%lf\n", x1, x2);

  }
  return 0;
}
```

## 8. Распечатка протокола

```
anastasia@anastasia-VirtualBox:~$ gcc -g lab10.c -lm

anastasia@anastasia-VirtualBox:~$ gdb a.out

GNU gdb (Ubuntu 9.2-0ubuntu1~20.04.1) 9.2

Copyright (C) 2020 Free Software Foundation, Inc.

License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>

This is free software: you are free to change and redistribute it.

There is NO WARRANTY, to the extent permitted by law.

Type "show copying" and "show warranty" for details.

This GDB was configured as "x86_64-linux-gnu".

Type "show configuration" for configuration details.

For bug reporting instructions, please see:

<http://www.gnu.org/software/gdb/bugs/>.

Find the GDB manual and other documentation resources online at:

<http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".

Type "apropos word" to search for commands related to "word"...

Reading symbols from a.out...

(gdb) help

List of classes of commands:

aliases -- Aliases of other commands.

breakpoints -- Making program stop at certain points.

data -- Examining data.

files -- Specifying and examining files.

internals -- Maintenance commands.

obscure -- Obscure features.

running -- Running the program.

stack -- Examining the stack.

status -- Status inquiries.

support -- Support facilities.

tracepoints -- Tracing of program execution without stopping the program.

user-defined -- User-defined commands.

Type "help" followed by a class name for a list of commands in that class.

Type "help all" for the list of all commands.

Type "help" followed by command name for full documentation.

Type "apropos word" to search for commands related to "word".

Type "apropos -v word" for full documentation of commands related to "word".

Command name abbreviations are allowed if unambiguous.

(gdb) list 1,19

1 #include <stdio.h>

2 #include <math.h>

3 int main(void){

4 double a, b, c, x1, x2, D;

5 scanf("%lf%lf%lf", &a, &b, &c);

6 D = b*b - 4*a*c;

7 if( D < 0 ){

8 printf("No roots\n");}

9 else if( D == 0 ){

10 x1 = -b/(2*a);

11 printf("One root: %lf\n", x1);

12 }

13 else {

14 x1 = (-b - sqrt(D)) / (2*a);

15 x2 = (-b + sqrt(D)) / (2*a);

16 printf("Two roots: %lf%lf\n", x1, x2);

17 }

18 return 0;

19 }

_(gdb)_ break main

Breakpoint 1 at 0x11c9: file lab10.c, line 3.

_(gdb)_ next

The program is not being run.

_(gdb)_ run

Starting program: /home/anastasia/a.out

Breakpoint 1, main () at lab10.c:3

3 int main(void){

(gdb) next

5 scanf("%lf%lf%lf", &a, &b, &c);

(gdb) print a

$1 = 4.6355705385357047e-310

(gdb) set var a=1

(gdb) print a

$2 = 1

(gdb) print b

$3 = 6.9533490934611385e-310

(gdb) set var b=5

(gdb) print b

$4 = 5

(gdb) print c

$5 = 4.6355705385319004e-310

(gdb) set var c=6

(gdb) print c

$6 = 6

(gdb) next

continue

6 D = b*b - 4*a*c;

(gdb) next

7 if( D < 0 ){

(gdb) next

9 else if( D == 0 ){

(gdb) next

14 x1 = (-b - sqrt(D)) / (2*a);

(gdb) next

15 x2 = (-b + sqrt(D)) / (2*a);

(gdb) next

16 printf("Two roots: %lf%lf\n", x1, x2);

(gdb) next

Two roots: -3.000000-2.000000

18 return 0;

(gdb) bt

#0 main () at lab10.c:18

(gdb) ptype a

type = double

(gdb) continue

Continuing.

[Inferior 1 (process 3519) exited normally]

(gdb) run

Starting program: /home/anastasia/a.out

Breakpoint 1, main () at lab10.c:3

3 int main(void){

(gdb) step

5 scanf("%lf%lf%lf", &a, &b, &c);

(gdb) set args 4 86 3

(gdb) continue

Continuing.

next

One root: -0.749999

[Inferior 1 (process 3529) exited normally]

(gdb) print a

$7 = {i = {0, 1045149306}, d = 1.2904777690891933e-08}

(gdb) quit
```

## 9. Дневник отладки

| № | Лаб.ИлиДом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| --- | --- | --- | --- | --- | --- | --- |
| 1 | Дом. | 29.10.22 | 13:48 | Отладка простейшей программы на С | - | - |

## 10. Замечания автора по существу работы

```
anastasia@anastasia-VirtualBox:~$ gcc -g lab9dop.c
anastasia@anastasia-VirtualBox:~$ gdb a.out
GNU gdb (Ubuntu 9.2-0ubuntu1~20.04.1) 9.2
Copyright (C) 2020 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from a.out...
(gdb) list 1,52
1	#include <math.h>
2	#include <stdbool.h>
3	#include <stdio.h>
4	#include <stdlib.h>
5	
6	int min(int a, int b) {
7	    return b < a ? b : a;
8	}
9	int max(int a, int b) {
10	    return a < b ? b : a;
11	}
12	
13	typedef struct {
14	    int i;
15	    int j;
16	    int l;
17	} Point;
18	
19	typedef struct {
20	    int x;
21	    int y;
22	    int r;
23	} Circle;
--Type <RET> for more, q to quit, c to continue without paging--
24	
25	Point updatePoint(Point p, int k) {
26	    Point next;
27	    next.i = (p.i * p.i * p.i - p.j * p.j * p.j + p.l * p.l * p.l - k) % 20;
28	    next.j = min(p.i * p.j * p.l - k, min(p.i * p.i * p.l - k, p.j * p.l * p.l - k)) % 30;
29	    next.l = max(p.i * p.j * p.l - k, max(p.i * p.i * p.l - k, p.j * p.l * p.l - k)) % 30;
30	    return next;
31	}
32	
33	bool isInCircle(Circle c, Point p) {
34	    int dx = p.i - c.x, dy = p.j - c.y;
35	    return dx * dx + dy * dy <= c.r * c.r;
36	}
37	
38	int main() {
39	    Point p = { 6, 27, -15 };
40	    Circle c = { -10, -10, 10 };
41	    Circle b = { -20, -20, 10 };
42	    for (int k = 0; k <= 50; ++k) {
43	        p = updatePoint(p, k);
--Type <RET> for more, q to quit, c to continue without paging--
44	        if (isInCircle(c, p) && isInCircle(b, p)) {
45	            printf("The point fell into the specified area at step %d with coordinates (%d, %d) and the motion parameter %d\n", k, p.i, p.j, p.l);
46	            break;
47	        }
48	        else if (k == 50)
49	            printf("In 50 moves, the dot never got to the area we needed.\nk=%d, i=%d, j=%d, l=%d\n", k, p.i, p.j, p.l);
50	    }
51	    return 0;
52	}
(gdb) break 47 if k = 20
Breakpoint 1 at 0x1432: file lab9dop.c, line 48.
(gdb) run
Starting program: /home/anastasia/a.out 

Breakpoint 1, main () at lab9dop.c:48
48	        else if (k == 50)
(gdb) print k
$1 = 20
(gdb) print p.i
$2 = -2
(gdb) print p
$3 = {i = -2, j = 0, l = 15}
(gdb) quit
```

## 11. Выводы

В ходе выполнения данной лабораторной работы были изучены команды для запуска программы с флагом -g и её отладке в gdb. Также были освоены команды (по запуску программы, построчному выполнению программы, отдельному присваиванию значений аргументов, определению типа переменных, остановке программы на определённой строке) для отладки простейшей программы на С при помощи gdb.

<b>Подпись студента:</b> ___________
