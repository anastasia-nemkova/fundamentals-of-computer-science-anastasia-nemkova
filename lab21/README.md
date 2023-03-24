# Отчёт по лабораторной работе №20 по курсу «Языки и методы программирования»

<b>Студент группы:</b> <ins>М8О-108Б-22, Немкова Анастасия Романовна, № по списку 13</ins>

<b>Контакты e-mail:</b> <ins>nastya.nemkova.04@mail.ru<ins>

<b>Работа выполнена:</b> «24» <ins>марта</ins> <ins>2023</ins>

<b>Преподаватель:</b> <ins>асп. каф.806 Сахарин Никита Александрович</ins>

<b>Отчет сдан</b> «25» <ins>марта</ins> <ins>2023</ins> г., <b>итоговая оценка</b> <ins></ins>

<b>Подпись преподавателя:</b> ___________

## 1. Тема

Программирование на интерпретируемых командных языках

## 2. Цель работы

Составить программу выполнения заданных действий над файлами на одном из интерпретируемом командном языке ОС UNIX - Bash

## 3. Задание (Вариант 13)

Удаление файлов с указанным префиксом, длина которых находится в указанном диапазоне

**Дополнительное задание**
1) Если указан параметр "??", то выводится подсказка (спецификация программы)
2) Если параметры опущены, то их значения должны быть запрошены у пользователя

## 4. Оборудование

Процессор: AMD RYZEN 7 5800H 3.20GHz ОП 16 ГБ

HDD: 952 ГБ

Монитор: 3840x2400

## 5. Программное обеспечение

Операционная система семейства: Linux Ubuntu, версия 22.04.1 LTS

Интерпретатор команд: bash, версия 5.0.17(1)

Система программирования: -

Редактор текстов: emacs

Местонахождение и имена файлов программ и данных на домашнем компьютере: -

## 6. Идея, метод, алгоритм решения задачи

1. Рассматриваем введенные аргументы. Если они некорректы, то выводим соответствующие сообщения, пока не будут введены верные аргументы.
2. При вводе "??" выводим спецификацию программы.
3. Рассматриваем файлы в директории lab21, ищем префикс и размер каждого файла.
4. Сравниваем с заданными пользователем параметрами.
5. Удаляем подходящие под заданные параметры файлы и выводим названия удаленных файлов.

## 7. Сценарий выполнения работы

```
#!/bin/bash

if [ $# -eq 0 -a "$1" != "??" ]
then
    while [ -z $prefix ]
    do
        echo -n "Enter the prefix, left and right border"
        read prefix bordleft bordright
    done
fi
if [ $# -le 1 -a "$1" != "??" ]
then
    while [ -z $bordleft ]
    do
        echo -n "Enter the left and right border"
        read bordleft bordright
    done
fi
if [ $# -le 2 -a "$1" != "??" ]
then
    while [ -z $bordright ]
    do
        echo -n "Enter the left border"
        read bordright
    done
fi
if [ $# -gt 3 ]
then
    while [ -z $bordright ]
    do
        echo -n "Enter the correct number of arguments"
        read prefix bordleft bordright
    done
fi
if [ "$1" = "??" ]
then
    echo "Specification: $0 <prefix> <leftbord> <rightbord>"
fi

if [ -z $prefix ]
then
    prefix=$1
fi
if [ -z $bordleft ]
then
    bordleft=$2
fi
if [ -z $bordright ]
then
    bordright=$3
fi
if [ "$1" != "??" ]
then
    for fl in ~/lab21/*.*
    do
        filename=$(basename $fl)
        prefixfile=${filename%.*}
        len=$(stat -c%s "$fl")
        if [[ "$prefixfile" == "$prefix" ]] && [[ "$len" -ge "$bordleft" ]] && [[ "$len" -le "$bordright" ]]
        then
            echo "Deleted file:" $fl
            rm $fl
        fi
    done
fi
```


**8. Распечатка протокола**

```
anastasia@anastasia-VirtualBox:~/lab21$ touch a.txt a a.ght s.txt a.sdf d a.c
anastasia@anastasia-VirtualBox:~/lab21$ ls
a  a.c  a.ght  a.sdf  a.txt  d  lab21.sh  s.txt
anastasia@anastasia-VirtualBox:~/lab21$ ./lab21.sh ??
Specification: ./lab21.sh <prefix> <leftbord> <rightbord>
anastasia@anastasia-VirtualBox:~/lab21$ ./lab21.sh
Enter the prefix, left and right border
Enter the prefix, left and right border b
Enter the left and right border 5 25
anastasia@anastasia-VirtualBox:~/lab21$ ./lab21.sh
Enter the prefix, left and right border a 2 200
Deleted file: /home/anastasia/lab21/a.ght
Deleted file: /home/anastasia/lab21/a.sdf
Deleted file: /home/anastasia/lab21/a.txt
anastasia@anastasia-VirtualBox:~/lab21$ ls
a  a.c  d  lab21.sh  s.txt
```

## 9. Дневник отладки

| **№** | **Лаб.Или Дом.** | **Дата** | **Время** | **Событие** | **Действие по исправлению** | **Примечание** |
| --- | --- | --- | --- | --- | --- | --- |
| **1** | **Дом.** | **24.03.23** | **13:00** | **Освоение команд ОС UNIX для обработки файлов** | **-** | **-** |

## 10. Замечания автора по существу работы


## 11. Выводы

Благодаря лабораторной работе были получениы навыки работы с Bash-скриптами.Был изучен синтаксис языка Bash. Было освоено отделение префикса файла от полного его имени и вычисление размера файла на Bash 

<b>Подпись студента:</b> ___________
