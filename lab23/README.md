# Отчёт по лабораторной работе №23 по курсу «Языки и методы программирования»

<b>Студент группы:</b> <ins>М8О-108Б-22, Немкова Анастасия Романовна, № по списку 13</ins>

<b>Контакты e-mail:</b> <ins>nastya.nemkova.04@mail.ru<ins>

<b>Работа выполнена:</b> «13» <ins>мая</ins> <ins>2023</ins>

<b>Преподаватель:</b> <ins>асп. каф.806 Сахарин Никита Александрович</ins>

<b>Отчет сдан</b> «13» <ins>мая</ins> <ins>2023</ins> г., <b>итоговая оценка</b> <ins></ins>

<b>Подпись преподавателя:</b> ___________

## 1. Тема

Динамические структуры данных. Обработка деревьев
  
## 2. Цель работы

Составить программу на языке СИ для построения и обработки дерева общего вида или упорядоченного двоичного дерева, содержащего узлы типа float. Основные функции работы с деревьями реализовать в виде универсальных процедур или функций. После того, как дерево создано, его обработка должна производиться в режиме текстового меню со следующими действиями: 
*	добавление нового узла (для двоичного дерева положение нового узла определяется в соответствии с требованием сохранения порядка; для дерева общего вида должен задаваться отец добавляемого узла. Добавляемый узел становится самым младшим сыном);
*	текстовая визуализация дерева (значение каждого узла выводится в отдельной строке, с отступом, пропорциональным глубине узла, в порядке старшинства узлов);
*	удаление узла (двоичное дерево перестраивается в соответствии с требованием сохранения целостности и порядка; для дерева общего вида удаляется все поддерево, исходящее из удаляемого узла. Должно быть предусмотрено корректное освобождение памяти);
*	вычисление значения некоторой функции от дерева (целой или логической), в соответствии с номером варианта.
  
## 3. Задание (Вариант 13)

Проверить, является ли дерево линейным списком вершин
  
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

`nodeLeftBrother()` - возвращает указатель на левого брата;
  
`nodeLeftmostChild()` - возвращает указатель на потомка;
  
`nodeParent()` - возвращает указатель на родителя;
  
`nodeRightBrother()` - возвращает указатель на правого брата;
  
`treeRoot()` - возвращает указатель на корень дерева;

`treeCreate()` - создание дерева;
  
`treePreorder()` - прямой обход дерева;
  
`treeInorder()` - центрированный обход дерева;
  
`treePostorder()` - обратный обход дерева;
  
`treeSearch()` - поиск элемента в дереве;
  
`nodeDelete()` - очистка узла дерева;
  
`treeDestroy()` - очистка дерева;
  
`treeInsert()` - вставка элемента дерева;
  
`treeErase()` - удаление элемента дерева;
  
`treeSize()` - размер дерева;
  
`treeIsEmpty()` - проверка дерева на пустоту;
  
`treeIsList ()` - проверка на линейный список вершин;
  
`treePrint()` - печать дерева;

## 7. Сценарий выполнения работы

**tree.h**
```
#ifndef TREE_H
#define TREE_H

#include <stddef.h>

typedef struct TreeNode TreeNode;

typedef struct {
    TreeNode *root;
    size_t size;
} Tree;

TreeNode *nodeLeftBrother(TreeNode *node);
TreeNode *nodeLeftmostChild(TreeNode *node);
TreeNode *nodeParent(TreeNode *node);
TreeNode *nodeRightBrother(TreeNode *node);
TreeNode *treeRoot(Tree *tree);

void treeCreate(Tree *tree);// создание дерева
void treePreorder(TreeNode *node); //прямой обход дерева
void treeInorder(TreeNode *node); //центрированный обход дерева
void treePostorder(TreeNode *node); //обратный обход дерева
TreeNode *treeSearch(TreeNode *node, float val); //поиск элемента в дереве
static size_t nodeDelete(TreeNode *node);// очистка узла дерева
void treeDestroy(Tree *tree);// очистка дерева
int treeInsert(Tree *tree, TreeNode *parent, float value);// вставка элемента дерева
void treeErase(Tree *tree, TreeNode *node);// удаление элемента дерева
size_t treeSize(const Tree * tree);// размер дерева
bool treeIsEmpty(const Tree * tree);// проверка дерева на пустоту
bool treeIsList (TreeNode * const node); // проверка на линейный список вершин
void treePrint(TreeNode *node, int level); //печать дерева

#endif // TREE_H_
```
**lab23.c**
```
#include <assert.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


#include "tree.h"

struct TreeNode {
    TreeNode *parent, *leftBrother, *rightBrother, *child;
    float value;
};

TreeNode *nodeLeftBrother(TreeNode * const node) {
    assert(node != NULL);
    return node->leftBrother;
}

TreeNode *nodeLeftmostChild(TreeNode * const node) {
    assert(node != NULL);
    return node->child;
}

TreeNode *nodeParent(TreeNode * const node) {
    assert(node != NULL);
    return node->parent;
}

TreeNode *nodeRightBrother(TreeNode * const node) {
    assert(node != NULL);
    return node->rightBrother;
}

TreeNode *treeRoot(Tree * const tree) {
    assert(tree != NULL);
    return tree->root;
}

void treeCreate(Tree * const tree) {
    tree -> root = NULL;
    tree -> size = 0;
}

void treePreorder(TreeNode * const node) {
    if (node == NULL){
        return;
    } 
    printf("%-.2f ", node->value);
    treePreorder(node -> child);
    treePreorder(node -> rightBrother);
} 

void treeInorder(TreeNode * const node) {
    if (node == NULL){ 
        return;
    }
    treeInorder(node -> child);
    printf("%-.2f ", node->value);
    treeInorder(node -> rightBrother); 
} 

void treePostorder(TreeNode * const node) {
    if (node == NULL){
        return;
    }
    treePostorder(node ->child);
    treePostorder(node -> rightBrother);
    printf("%-.2f ", node->value);
} 

TreeNode *treeSearch(TreeNode * const node, const float val) {
    if (node == NULL || node->value == val) return node; 
    TreeNode *child = node->child; 
    while (child != NULL) {
        TreeNode *result = treeSearch(child, val); 
        if (result != NULL) return result; 
        child = child->rightBrother; 
    } 
    return NULL; 
}

static size_t nodeDelete(TreeNode * const node) {
    // free all node in subtree of `node`
    // returns count of nodes in subtree
    if(node == 0){
        return 0;
    }
    size_t count = 1;
    TreeNode *child = node -> child;
    while(child != NULL){
        count += nodeDelete(child);
        child = child -> rightBrother;
    }
    free(node);
    return count;
}

void treeDestroy(Tree * const tree){
    assert(tree != NULL);
    if(tree -> root != NULL){
        nodeDelete(tree -> root);
    }
    tree -> size = 0;
}

int treeInsert(Tree * const tree, TreeNode * const parent, const float value) {
    assert(tree != NULL && (tree->root != NULL || parent == NULL));
    TreeNode * const node = (TreeNode *)malloc(sizeof(TreeNode));
    if (node == NULL)
        return errno;
    node->parent = parent;
    node->leftBrother = node->child = NULL;
    node->value = value;
    if (parent != NULL) {
        node->rightBrother = parent->child;
        if (parent->child != NULL)
            parent->child->leftBrother = node;
        parent->child = node;
    } else {
        node->rightBrother = NULL;
        tree->root = node;
    }
    ++tree->size;
    return 0;
}

void treeErase(Tree * const tree, TreeNode * const node) {
    assert(tree != NULL && tree->root != NULL);
    if (node->leftBrother != NULL)
        node->leftBrother->rightBrother = node->rightBrother;
    else if (node->parent != NULL)
        node->parent->child = node->rightBrother;
    else
        tree->root = NULL;

    if (node->rightBrother != NULL)
        node->rightBrother->leftBrother = node->leftBrother;

    tree->size -= nodeDelete(node);
}

size_t treeSize(const Tree * const tree){
    return tree -> size;
}

bool treeIsEmpty(const Tree * const tree){
    return tree -> size == 0;
}

//если текущий потомок имеет больше одного потомка, то не лин. список
bool treeIsList (TreeNode * const node) {
    if (node == NULL) {
        return true;
    }
    if ((node -> child != NULL) && (node -> child -> rightBrother != NULL)){
        return false;
    }
    return treeIsList(node -> child) && treeIsList(node -> rightBrother);
}

void treePrint(TreeNode * const node, int level) {
    if(node == NULL){
        return;
    }
    for (int i = 0; i < level; i++) {
        printf("-");
    }
    printf("%-.2f\n", node -> value);
    treePrint(node -> child, level + 1);
    treePrint(node -> rightBrother, level);
}

int main() {
    Tree *tree = malloc(sizeof(Tree));;
    treeCreate(tree);

    treeInsert(tree, NULL, 1);
    treeInsert(tree, tree -> root, 2.5);

    treeInsert(tree, tree -> root, 6.9);
    treeInsert(tree, tree -> root -> child, 7.6);
    treeInsert(tree, tree -> root -> child, 45.7);
    treeInsert(tree, tree -> root -> child -> rightBrother, 12.5);
    treeInsert(tree, tree -> root -> child, 4.1);
    treeInsert(tree, tree -> root -> child -> child, 5.7);
    treeInsert(tree, tree -> root -> child -> child -> rightBrother, 8.9);
    treeInsert(tree, tree -> root -> child -> child, 71.2);
    treeInsert(tree, tree -> root -> child -> child -> rightBrother -> child, 63.3);
    treeInsert(tree, tree -> root -> child, 1.2);
    
    treeInsert(tree, tree -> root, 3.6);
    treeInsert(tree, tree -> root -> child, 15.5);
    treeInsert(tree, tree -> root -> child, 5.69);
    
    
    printf("-\nSize of the tree = %ld\n", treeSize(tree));
    treePrint(tree -> root, 0);
    if (treeIsList(tree -> root)){ 
        printf("Yes, a tree is a linear list of vertices\n");
    }else {
        printf("No, a tree is not a linear list of vertices\n");
    }
    treePreorder(tree -> root);
    printf("\n");
    treeInorder(tree -> root);
    printf("\n");
    treePostorder(tree -> root);
    printf("\n"); 

    treeErase(tree, tree -> root -> child -> child);
    printf("-\nSize of the tree = %ld\n", treeSize(tree));
    treePrint(tree -> root, 0);
    if (treeIsList(tree -> root)){ 
        printf("Yes, a tree is a linear list of vertices\n");
    }else {
        printf("No, a tree is not a linear list of vertices\n");
    }
    if (treeSearch(tree -> root, 12.5)){
        printf("YES\n");
    } else{
        printf("NO\n");
    }
    treePreorder(tree -> root);
    printf("\n");
    treeInorder(tree -> root);
    printf("\n");
    treePostorder(tree -> root);
    printf("\n");
    
    treeErase(tree, tree -> root -> child -> rightBrother -> child);
    printf("-\nSize of the tree = %ld\n", treeSize(tree));
    treePrint(tree -> root, 0);
    if (treeIsList(tree -> root)){
        printf("Yes, a tree is a linear list of vertices\n");
    }else {
        printf("No, a tree is not a linear list of vertices\n");
    }
    treePreorder(tree -> root);
    printf("\n");
    treeInorder(tree -> root);
    printf("\n");
    treePostorder(tree -> root);
    printf("\n");
    
    treeErase(tree, tree -> root -> child -> rightBrother -> child);
    treeErase(tree, tree -> root -> child -> rightBrother -> child -> rightBrother);
    printf("-\nSize of the tree = %ld\n", treeSize(tree));
    treePrint(tree -> root, 0);
    if (treeIsList(tree -> root)){ 
        printf("Yes, a tree is a linear list of vertices\n");
    }else {
        printf("No, a tree is not a linear list of vertices\n");
    }
    treePreorder(tree -> root);
    printf("\n");
    treeInorder(tree -> root);
    printf("\n");
    treePostorder(tree -> root);
    printf("\n");

    treeErase(tree, tree -> root -> child);
    treeErase(tree, tree -> root -> child -> rightBrother);
    printf("-\nSize of the tree = %ld\n", treeSize(tree));
    treePrint(tree -> root, 0);
    if (treeIsList(tree -> root)){ 
        printf("Yes, a tree is a linear list of vertices\n");
    }else {
        printf("No, a tree is not a linear list of vertices\n");
    }
    treePreorder(tree -> root);
    printf("\n");
    treeInorder(tree -> root);
    printf("\n");
    treePostorder(tree -> root);
    printf("\n");

    treeDestroy(tree);
    printf("-\nSize of the tree = %ld\n", treeSize(tree));
}
```
        
**8. Распечатка протокола**

```
arnemkova@LAPTOP-TA2RV74U:~/LABS/lab23$ gcc lab23.c
arnemkova@LAPTOP-TA2RV74U:~/LABS/lab23$ ./a.out
-
Size of the tree = 15
1.00
-3.60
--5.69
--15.50
-6.90
--1.20
--4.10
---71.20
---5.70
--45.70
---8.90
----63.30
--7.60
-2.50
--12.50
No, a tree is not a linear list of vertices
1.00 3.60 5.69 15.50 6.90 1.20 4.10 71.20 5.70 45.70 8.90 63.30 7.60 2.50 12.50
5.69 15.50 3.60 1.20 71.20 5.70 4.10 63.30 8.90 45.70 7.60 6.90 12.50 2.50 1.00
15.50 5.69 5.70 71.20 63.30 8.90 7.60 45.70 4.10 1.20 12.50 2.50 6.90 3.60 1.00
-
Size of the tree = 14
1.00
-3.60
--15.50
-6.90
--1.20
--4.10
---71.20
---5.70
--45.70
---8.90
----63.30
--7.60
-2.50
--12.50
No, a tree is not a linear list of vertices
YES
1.00 3.60 15.50 6.90 1.20 4.10 71.20 5.70 45.70 8.90 63.30 7.60 2.50 12.50
15.50 3.60 1.20 71.20 5.70 4.10 63.30 8.90 45.70 7.60 6.90 12.50 2.50 1.00
15.50 5.70 71.20 63.30 8.90 7.60 45.70 4.10 1.20 12.50 2.50 6.90 3.60 1.00
-
Size of the tree = 13
1.00
-3.60
--15.50
-6.90
--4.10
---71.20
---5.70
--45.70
---8.90
----63.30
--7.60
-2.50
--12.50
No, a tree is not a linear list of vertices
1.00 3.60 15.50 6.90 4.10 71.20 5.70 45.70 8.90 63.30 7.60 2.50 12.50
15.50 3.60 71.20 5.70 4.10 63.30 8.90 45.70 7.60 6.90 12.50 2.50 1.00
15.50 5.70 71.20 63.30 8.90 7.60 45.70 4.10 12.50 2.50 6.90 3.60 1.00
-
Size of the tree = 9
1.00
-3.60
--15.50
-6.90
--45.70
---8.90
----63.30
-2.50
--12.50
No, a tree is not a linear list of vertices
1.00 3.60 15.50 6.90 45.70 8.90 63.30 2.50 12.50
15.50 3.60 63.30 8.90 45.70 6.90 12.50 2.50 1.00
15.50 63.30 8.90 45.70 12.50 2.50 6.90 3.60 1.00
-
Size of the tree = 5
1.00
-6.90
--45.70
---8.90
----63.30
Yes, a tree is a linear list of vertices
1.00 6.90 45.70 8.90 63.30
63.30 8.90 45.70 6.90 1.00
63.30 8.90 45.70 6.90 1.00
-
Size of the tree = 0
```

## 9. Дневник отладки

| **№** | **Лаб.Или Дом.** | **Дата** | **Время** | **Событие** | **Действие по исправлению** | **Примечание** |
| --- | --- | --- | --- | --- | --- | --- |
| **1** | **Дом.** | **12.05.23** | **13:00** | **Выполнение лабораторной работы** | **-** | **-** |

## 10. Замечания автора по существу работы
[Защита с олимпроги](https://mai2022.contest.codeforces.com/group/Ej1bTQMkro/contest/427393/submission/201038449)

[Защита с олимпроги](https://mai2022.contest.codeforces.com/group/Ej1bTQMkro/contest/427393/submission/201032473)

[Защита с олимпроги](https://mai2022.contest.codeforces.com/group/Ej1bTQMkro/contest/427393/submission/201030603)

## 11. Выводы

В ходе выполнения данной лабораторной работы было изучено создание общего дерева на СИ. Были составлены функции по добавлению, удалению, поиску элемента дерева, очистке и печати всего дерева, были рассмотрены три метода обхода дерева Pre-order, In-order и Post-order, также было выявлено является ли заданное дерево линейным списком вершин.

<b>Подпись студента:</b> ___________
