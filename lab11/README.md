# Отчёт по лабораторной работе №11 по курсу «Фундаментальная информатика»

<b>Студент группы:</b> <ins>М8О-108Б-22, Немкова Анастасия Романовна, № по списку 14</ins>

<b>Контакты e-mail:</b> <ins>nastya.nemkova.04@mail.ru<ins>

<b>Работа выполнена:</b> «18» <ins>ноября</ins> <ins>2022</ins>

<b>Преподаватель:</b> <ins>асп. каф.806 Сахарин Никита Александрович</ins>

<b>Отчет сдан</b> «26» <ins>ноябрь</ins> <ins>2022</ins> г., <b>итоговая оценка</b> <ins>5

<b>Подпись преподавателя:</b> ___________

## 1. Тема
  
Обработка последовательности литер входного текстового файла. Простейшие приёмы лексического анализа. Диаграммы состояний и переходов. 

## 2. Цель работы

Составить программу на языке Си, выполняющую анализ и обработку вводимого текста в соответствии с заданием.

## 3. Задание

Подсчитать контрольные суммы всех слов исходного текста.

## 4. Оборудование

Процессор: AMDRYZEN 7 5800H 3.20GHz ОП 16 ГБ

НDD: 952 ГБ

Монитор: 3840 × 2400

## 5. Программное обеспечение

Операционная система семейства: LinuxUbuntu, версия 22.04.1 LTS

Интерпретатор команд: bash, версия 5.0.17(1)

Система программирования: gcc

Редактор текстов: emacs

## 6. Идея, метод, алгоритм решения задачи

1. Подсчитываем простую контрольную сумму;
2. Вводим функцию для вывода массива:
   - выделяем память под массиы;
   - берём по одному символу из строки и вводим условие на проверку полученного знака;
   - если это какой-то знак препинания или пробел, то обрабатываем полученную до этого стороку и зануляем её размер;
   - если не встречаем спец.символ, то добавляем этот элемент на текущую пустую позицию и увеличиваем длину текущего слова на 1.
   
## 7. Сценарий выполнения работы


Код программы:

```
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

unsigned int max_size = 50;

unsigned long control_sum(const unsigned char word[], unsigned int length) {
    unsigned long res = 0;
    const long big_num = 1103515245;
    for (int i = 0; i < length; i++) {
        res += word[i] * big_num() % 15250;
    }
    return res;
}

void print(const unsigned char word[], unsigned int length) {
    for (unsigned int i = 0; i < length; ++i) {
        printf("%c", word[i]);
     }
    printf(": %lu\n", control_sum(word, length));
}

void processing_string() {
    unsigned char *curr_word = malloc(sizeof(char) * max_size); // текущее слово
    unsigned int len = 0; // длина слова (от 0)
    int sym;
    sym = getchar();
    while (sym != EOF) {
        if ( sym == '\n' || sym == '\r' || sym == ' ' || sym == '.' || sym == ',' ) {
            if (len) {
                print(curr_word, len);
                len = 0;
            }
        } else {
            if (len == max_size) {
                curr_word = realloc(curr_word, max_size * 2);
                max_size *= 2;
            }
            curr_word[len] = sym;
            ++len;
        }
        if ((sym = getchar()) == EOF) {
            if (len) {
                printf("%s:%lu", curr_word, control_sum(curr_word, len));
                break;
            }
        } else {
            continue;
        }
    }
}

int main() {
    processing_string(); 
    return 0;
}
```

## 8. Распечатка протокола

```
anastasia@anastasia-VirtualBox:~$ gcc lab11.c
anastasia@anastasia-VirtualBox:~$ ./a.out
hello world!
hello: 40840
world!: 67325
^C
anastasia@anastasia-VirtualBox:~$ gcc lab11.c
anastasia@anastasia-VirtualBox:~$ ./a.out
i water flowers everyday
i: 12475
water: 38265
flowers: 71150
everyday: 48385
^C

```

## 9. Дневник отладки

| № | Лаб.ИлиДом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| --- | --- | --- | --- | --- | --- | --- |
| 1 | Дом. | 12.11.22 | 13:48 | Написание программы на Си | - | - |

## 10. Замечания автора по существу работы

  Вычисление контрольной суммы слов исходного текста с использованием функции getchar, switch и case
  
```
#include <stdio.h>

typedef enum {
    READING,
    FIRST_LIMITATION,
    SECOND,
    TRANSLATION,
    HASHING,
    ENTER,
}Step;

Step step = READING;
     
void hash_f() {
    int hash = 0;
    int sim;
    long p = 1;
    const int mod = 1e9 + 7, k = 31;
    for(char word = getchar(); word != EOF ; word = getchar()) {
        switch(step) {
            case READING:
                if(word != ' ') {
                    step = ENTER;
                }
                if(word == ' ') {
                    goto stop;
                    break;
                }
            case ENTER:
                if(word == '\n') {
                    printf("hash is %d\n", hash);
                    break;
                }
                if(word != '\n') {
                    step = FIRST_LIMITATION;     
                }
            case FIRST_LIMITATION:
                if(word == '!' || word == '.' || word == '\t' || word == '\r') {
                    step = TRANSLATION;
                }    
            case TRANSLATION:
                sim = word;
                step = HASHING;
                printf("%d\n", sim);
            case HASHING:
                hash = (hash + sim * p) % mod;
                p = (p * k) % mod;
                step = READING;
                continue;

                
        }
    stop: printf("hash is %d\n", hash); continue;   
    }
    
}
                 
int main(){
    hash_f();
    return 0;
}
```

## 11. Выводы

В ходе выполнения лабораторной работы были получены навыки по написанию программы для анализа вводимого текста. Были изучены функция getchar,оператор множественного выбора switch,case, создание массивов, функции malloc и realloc, управляющие символы. Было освоено написание кода для вычесления контрольной суммы слов вводимого текста с использованием полиномиальной хеш-функции.

<b>Подпись студента:</b> ___________
