# Отчёт по лабораторной работе №24 по курсу «Языки и методы программирования»

<b>Студент группы:</b> <ins>М8О-108Б-22, Немкова Анастасия Романовна, № по списку 13</ins>

<b>Контакты e-mail:</b> <ins>nastya.nemkova.04@mail.ru<ins>

<b>Работа выполнена:</b> «27» <ins>мая</ins> <ins>2023</ins>

<b>Преподаватель:</b> <ins>асп. каф.806 Сахарин Никита Александрович</ins>

<b>Отчет сдан</b> «27» <ins>мая</ins> <ins>2023</ins> г., <b>итоговая оценка</b> <ins></ins>

<b>Подпись преподавателя:</b> ___________

## 1. Тема

Преобразования выражени в дерево
  
## 2. Цель работы

Составить пpoгpамму выполнения заданных преобразоnапий арифметических выражений с применением деревьев.
  
## 3. Задание (Вариант 13)

Упростить выражение, убрав из него все произведения, в которых в качестве сомножителя используется 0.
  
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

``size_t treeSize(Node* node)`` - размер дерева;

``Node* createOperatorNode(char op, Node* left, Node* right)`` - создание узла знака;

``Node* createValueNode(double value)`` - создание узла значения;

``Node* createVariableNode(const char* variable)`` - создание узла переменной;

``void deleteExpressionTree(Node* root)`` - очистка дерева;

``void printNode(Node* node)`` - печать дерева в виде выражения;

``void printExpressionTree(Node* node, int level)`` - печать дерева в обычном представлении ;

``Node* simplifyExpression(Node* root)`` - удаление произведений с нулевым сомножителем и слагаемых, равных нулю;

``void prefixTraversal(Node* node)`` - префиксный обход;

``void infixTraversal(Node* node)`` - инфиксный обход;

``void postfixTraversal(Node* node)`` - постфиксный обход;

## 7. Сценарий выполнения работы

**tree.h**
  ```
  #ifndef TREE_H
#define TREE_H

#define VARIABLE_LENGTH (8U)
#define NODES_LENGTH (512U)

typedef struct Node Node;

typedef struct {
    Node *left, *right;
    char op;
} Operator;

typedef union {
    Operator op;
    double value;
    char variable[VARIABLE_LENGTH];
} NodeUnion;

typedef enum {
    OPERATOR,
    VALUE,
    VARIABLE
} NodeType;

struct Node {
    Node *parent;
    NodeUnion nodeUnion;
    NodeType nodeType;
};


size_t treeSize(Node* node);

Node* createOperatorNode(char op, Node* left, Node* right);

Node* createValueNode(double value);

Node* createVariableNode(const char* variable);

void deleteExpressionTree(Node* root);

void printNode(Node* node);

void printExpressionTree(Node* node, int level);

Node* simplifyExpression(Node* root);

void prefixTraversal(Node* node);

void infixTraversal(Node* node);

void postfixTraversal(Node* node);

#endif //_TREE_H_
```
  
  **tree.c**
  ```
 #include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include "tree.h"

size_t treeSize(Node* node) {
    if (node == NULL)
        return 0;
    int size = 1;
    if (node->nodeType == OPERATOR) {
        size += treeSize(node->nodeUnion.op.left);
        size += treeSize(node->nodeUnion.op.right);
    }
    return size;
}

Node* createNode(NodeType type) {
    Node *node = (Node*)malloc(sizeof(Node));
    node->parent = NULL;
    node->nodeType = type;
    return node;
}

// Создание узла-оператора
Node* createOperatorNode(char op, Node* left, Node* right) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->nodeType = OPERATOR;
    node->nodeUnion.op.left = left;
    node->nodeUnion.op.right = right;
    node->nodeUnion.op.op = op;
    return node;
}

// Создание узла-значения
Node* createValueNode(double value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->nodeType = VALUE;
    node->nodeUnion.value = value;
    return node;
}

// Создание узла-переменной
Node* createVariableNode(const char* variable) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->nodeType = VARIABLE;
    strncpy(node->nodeUnion.variable, variable, VARIABLE_LENGTH);
    return node;
}

void deleteExpressionTree(Node* root) {
    if (root == NULL){
        return;
    }
    if (root->nodeType == OPERATOR) {
        deleteExpressionTree(root->nodeUnion.op.left);
        deleteExpressionTree(root->nodeUnion.op.right);
    }
    
    free(root);
}


void printNode(Node* node) {
    if (node == NULL)
        return;
    
    if (node->nodeType == OPERATOR) {
        if(node->nodeUnion.op.left == NULL || node->nodeUnion.op.right == NULL){
            return;
        }
        printf("(");
        printNode(node->nodeUnion.op.left);
        printf(" %c ", node->nodeUnion.op.op);
        printNode(node->nodeUnion.op.right);
        printf(")");
    } else if (node->nodeType == VALUE) {
        printf("%.2f", node->nodeUnion.value);
    } else if (node->nodeType == VARIABLE) {
        printf("%s", node->nodeUnion.variable);
    }
}

void printExpressionTree(Node* node, int level) {
    if (node == NULL)
        return;

    if (node->nodeType == OPERATOR) {
        printExpressionTree(node->nodeUnion.op.left, level + 1);
        for (int i = 0; i < level; i++)
            printf("\t");
        printf("%c\n", node->nodeUnion.op.op); 

        printExpressionTree(node->nodeUnion.op.right, level + 1);

    } else if (node->nodeType == VALUE) {
        for (int i = 0; i < level; i++)
            printf("\t");

        printf("%.2f\n", node->nodeUnion.value);
    } else if (node->nodeType == VARIABLE) {
        for (int i = 0; i < level; i++)
            printf("\t");

        printf("%s\n", node->nodeUnion.variable);
    }
}

int isOperator(char c) {
    return (c == '+'||  c == '-' || c == '*' || c == '/' || c == '^');
}

int getOperatorPriority(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/' || op == '^')
        return 2;
    else
        return 0;
}

int isUnaryMinus(const char* infix, int index) {
    if (index == 0){
        return 1;
    }
    char prevChar = infix[index - 1];
    return (isOperator(prevChar) || prevChar == '(' || prevChar == ' ');
}

Node* ExpressionTreeFromPostfix(const char* postfix) {
    int len = strlen(postfix);
    Node* stack[len];
    int top = -1;

    for (int i = 0; i < len; i++) {
        char c = postfix[i];

        if (isdigit(c) || (c == '-' && isUnaryMinus(postfix, i))) {
            char number[20];
            int numberIndex = 0;
            if (c == '-') {
                number[numberIndex++] = '-';
                i++;
            }
            while (isdigit(postfix[i])) {
                number[numberIndex++] = postfix[i++];
            }
            number[numberIndex] = '\0';

            double value = atof(number);
            Node* valueNode = createValueNode(value);
            stack[++top] = valueNode;
        } else if (isalpha(c)) {
            char variable[2] = {c, '\0'};
            Node* variableNode = createVariableNode(variable);
            stack[++top] = variableNode;
        } else if (isOperator(c)) {
            Node* rightOperand = stack[top--];
            Node* leftOperand = stack[top--];
            Node* operatorNode = createOperatorNode(c, leftOperand, rightOperand);
            stack[++top] = operatorNode;
        }
    }

    return stack[top];
}


Node* ExpressionTreeFromInfix(const char* infix) {
    int len = strlen(infix);
    char postfix[len * 2];
    int postfixIndex = 0;

    char stack[len];
    int top = -1;

    for (int i = 0; i < len; i++) {
        char c = infix[i];

        if (isdigit(c) || (c == '-' && isUnaryMinus(infix, i))) {
            while (isdigit(infix[i]) || (infix[i] == '-' && isUnaryMinus(infix, i))) {
                postfix[postfixIndex++] = infix[i++];
            }
            postfix[postfixIndex++] = ' ';
            i--;
        } else if (isalpha(c)) {
            while (isalpha(infix[i])) {
                postfix[postfixIndex++] = infix[i++];
            }
            postfix[postfixIndex++] = ' ';
            i--;
        } else if (isOperator(c)) {
            if (c == '^') {
                while (top >= 0 && stack[top] != '(' && getOperatorPriority(stack[top]) > getOperatorPriority(c)) {
                    postfix[postfixIndex++] = stack[top--];
                    postfix[postfixIndex++] = ' ';
                }
            } else {
                while (top >= 0 && stack[top] != '(' && getOperatorPriority(stack[top]) >= getOperatorPriority(c)) {
                    postfix[postfixIndex++] = stack[top--];
                    postfix[postfixIndex++] = ' ';
                }
            }
            stack[++top] = c;
        } else if (c == '(') {
            stack[++top] = c;
        } else if (c == ')') {
            while (top >= 0 && stack[top] != '(') {
                postfix[postfixIndex++] = stack[top--];
                postfix[postfixIndex++] = ' ';
            }
            top--;
        }
    }

    while (top >= 0) {
        postfix[postfixIndex++] = stack[top--];
        postfix[postfixIndex++] = ' ';
    }

    postfix[postfixIndex] = '\0';
    return ExpressionTreeFromPostfix(postfix);
}



// Убираем все произведения с нулевыми сомножителями
Node* simplifyExpression(Node* root) {
    if (root == NULL)
        return NULL;
    
    if (root->nodeType == OPERATOR) {

        root->nodeUnion.op.left = simplifyExpression(root->nodeUnion.op.left);
        root->nodeUnion.op.right = simplifyExpression(root->nodeUnion.op.right);
        root->nodeUnion.op.left->parent = root->nodeUnion.op.right->parent = root;
        if (root->nodeUnion.op.op == '*') {
            if (root->nodeUnion.op.left->nodeType == VALUE  && root->nodeUnion.op.left->nodeUnion.value == 0.0) {
                deleteExpressionTree(root->nodeUnion.op.right);
                Node * left = root->nodeUnion.op.left; 
                free(root);
                return left;
            }
            
            if (root->nodeUnion.op.right->nodeType == VALUE && root->nodeUnion.op.right->nodeUnion.value == 0.0) {
                deleteExpressionTree(root->nodeUnion.op.left);
                Node * right = root->nodeUnion.op.right;
                free(root);
                return right;
            }
        //Удаляем лишние нули
        } else if(root->nodeUnion.op.op == '+'){
            if (root->nodeUnion.op.left->nodeType == VALUE && root->nodeUnion.op.left->nodeUnion.value == 0.0){
                Node *right = root->nodeUnion.op.right;
                deleteExpressionTree(root->nodeUnion.op.left);
                *root = *right;
                free(right);
            }
            if (root->nodeUnion.op.right->nodeType == VALUE && root->nodeUnion.op.right->nodeUnion.value == 0.0){
                Node *left = root->nodeUnion.op.left;
                deleteExpressionTree(root->nodeUnion.op.right);
                *root = *left;
                free(left);
            }
        }
        
    }
    return root;
}

void prefixTraversal(Node* node) {
    if (node == NULL)
        return;
    if (node->nodeType == OPERATOR) {
        printf("%c ", node->nodeUnion.op.op);
        prefixTraversal(node->nodeUnion.op.left);
        prefixTraversal(node->nodeUnion.op.right);
    } else if (node->nodeType == VALUE) {
        printf("%.2f ", node->nodeUnion.value);
    } else if (node->nodeType == VARIABLE) {
        printf("%s ", node->nodeUnion.variable);
    }
}

void infixTraversal(Node* node) {
    if (node == NULL)
        return;
    if (node->nodeType == OPERATOR) {
        infixTraversal(node->nodeUnion.op.left);
        printf("%c ", node->nodeUnion.op.op);
        infixTraversal(node->nodeUnion.op.right);
    } else if (node->nodeType == VALUE) {
        printf("%.2f ", node->nodeUnion.value);
    } else if (node->nodeType == VARIABLE) {
        printf("%s ", node->nodeUnion.variable);
    }
}

void postfixTraversal(Node* node) {
    if (node == NULL)
        return;
    if (node->nodeType == OPERATOR) {
        postfixTraversal(node->nodeUnion.op.left);
        postfixTraversal(node->nodeUnion.op.right);
        printf("%c ", node->nodeUnion.op.op);
    } else if (node->nodeType == VALUE) {
        printf("%.2f ", node->nodeUnion.value);
    } else if (node->nodeType == VARIABLE) {
        printf("%s ", node->nodeUnion.variable);
    }
}

double pow(double base, double exponent) {
    double result = 1.0;
    int positiveExponent = (exponent >= 0);
    
    if (!positiveExponent) {
        exponent = -exponent;
    }
    
    while (exponent > 0) {
        result *= base;
        exponent--;
    }
    
    return (positiveExponent) ? result : 1.0 / result;
}

double treeCalculator(Node* node) {
    if (node == NULL)
        return 0.0;
    
    if (node->nodeType == OPERATOR) {
        double leftValue = treeCalculator(node->nodeUnion.op.left);
        double rightValue = treeCalculator(node->nodeUnion.op.right);
        double value;
        
        switch (node->nodeUnion.op.op) {
            case '+':
                return leftValue + rightValue;
            case '-':
                return leftValue - rightValue;
            case '*':
                return leftValue * rightValue;
            case '/':
                return leftValue / rightValue;
            case '^':
                return pow(leftValue, rightValue);
        }
    } else if (node->nodeType == VALUE) {
        return node->nodeUnion.value;
    }
    
    return 0;
}

int main(void) {
    char infixExpression[NODES_LENGTH];
    printf("Enter the expression:\n");
    fgets(infixExpression, sizeof(infixExpression), stdin);
    infixExpression[strcspn(infixExpression, "\n")] = '\0';
    Node* expressionTree = ExpressionTreeFromInfix(infixExpression);

    printf("Expression tree:\n");
    printExpressionTree(expressionTree, 0);

    printf("Tree size: %ld\n", treeSize(expressionTree));
    
    printf("\nPrefix traversal: ");
    prefixTraversal(expressionTree);
    printf("\nInfix traversal: ");
    infixTraversal(expressionTree);
    printf("\nPostfix traversal: ");
    postfixTraversal(expressionTree);
    printf("\n-----\n");

    printf("Original expression: ");
    printNode(expressionTree);

    simplifyExpression(expressionTree);
    
    printf("\nSimplified expression: ");
    printNode(expressionTree);

    printf("\nTree size: %ld\n", treeSize(expressionTree));
    printExpressionTree(expressionTree, 0);

    printf("-----\n");
    
    double result = treeCalculator(expressionTree);
    printf("Result: %.2f\n", result);

    deleteExpressionTree(expressionTree);
    
    return 0;
}
  ```
        
## 8. Распечатка протокола

```
  arnemkova@LAPTOP-TA2RV74U:~/LABS/lab24$ gcc tree.c
arnemkova@LAPTOP-TA2RV74U:~/LABS/lab24$ valgrind --leak-check=full ./a.out
==5997== Memcheck, a memory error detector
==5997== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==5997== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
==5997== Command: ./a.out
==5997==
Enter the expression:
((4+(-5))+8)+((8/5)*(3*0))
Expression tree:
                        4.00
                +
                        -5.00
        +
                8.00
+
                        8.00
                /
                        5.00
        *
                        3.00
                *
                        0.00
Tree size: 13

Prefix traversal: + + + 4.00 -5.00 8.00 * / 8.00 5.00 * 3.00 0.00
Infix traversal: 4.00 + -5.00 + 8.00 + 8.00 / 5.00 * 3.00 * 0.00
Postfix traversal: 4.00 -5.00 + 8.00 + 8.00 5.00 / 3.00 0.00 * * +
-----
Original expression: (((4.00 + -5.00) + 8.00) + ((8.00 / 5.00) * (3.00 * 0.00)))
Simplified expression: ((4.00 + -5.00) + 8.00)
Tree size: 5
                4.00
        +
                -5.00
+
        8.00
-----
Result: 7.00
==5997==
==5997== HEAP SUMMARY:
==5997==     in use at exit: 0 bytes in 0 blocks
==5997==   total heap usage: 15 allocs, 15 frees, 2,568 bytes allocated
==5997==
==5997== All heap blocks were freed -- no leaks are possible
==5997==
==5997== For lists of detected and suppressed errors, rerun with: -s
==5997== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
arnemkova@LAPTOP-TA2RV74U:~/LABS/lab24$ valgrind --leak-check=full ./a.out
==5999== Memcheck, a memory error detector
==5999== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==5999== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
==5999== Command: ./a.out
==5999==
Enter the expression:
5 ^ 3 ^ 2
Expression tree:
        5.00
^
                3.00
        ^
                2.00
Tree size: 5

Prefix traversal: ^ 5.00 ^ 3.00 2.00
Infix traversal: 5.00 ^ 3.00 ^ 2.00
Postfix traversal: 5.00 3.00 2.00 ^ ^
-----
Original expression: (5.00 ^ (3.00 ^ 2.00))
Simplified expression: (5.00 ^ (3.00 ^ 2.00))
Tree size: 5
        5.00
^
                3.00
        ^
                2.00
-----
Result: 1953125.00
==5999==
==5999== HEAP SUMMARY:
==5999==     in use at exit: 0 bytes in 0 blocks
==5999==   total heap usage: 7 allocs, 7 frees, 2,248 bytes allocated
==5999==
==5999== All heap blocks were freed -- no leaks are possible
==5999==
==5999== For lists of detected and suppressed errors, rerun with: -s
==5999== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
arnemkova@LAPTOP-TA2RV74U:~/LABS/lab24$ valgrind --leak-check=full ./a.out
==6000== Memcheck, a memory error detector
==6000== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==6000== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
==6000== Command: ./a.out
==6000==
Enter the expression:
(5 ^ 3) ^ 2
Expression tree:
                5.00
        ^
                3.00
^
        2.00
Tree size: 5

Prefix traversal: ^ ^ 5.00 3.00 2.00
Infix traversal: 5.00 ^ 3.00 ^ 2.00
Postfix traversal: 5.00 3.00 ^ 2.00 ^
-----
Original expression: ((5.00 ^ 3.00) ^ 2.00)
Simplified expression: ((5.00 ^ 3.00) ^ 2.00)
Tree size: 5
                5.00
        ^
                3.00
^
        2.00
-----
Result: 15625.00
==6000==
==6000== HEAP SUMMARY:
==6000==     in use at exit: 0 bytes in 0 blocks
==6000==   total heap usage: 7 allocs, 7 frees, 2,248 bytes allocated
==6000==
==6000== All heap blocks were freed -- no leaks are possible
==6000==
==6000== For lists of detected and suppressed errors, rerun with: -s
==6000== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
arnemkova@LAPTOP-TA2RV74U:~/LABS/lab24$ valgrind --leak-check=full ./a.out
==6001== Memcheck, a memory error detector
==6001== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==6001== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
==6001== Command: ./a.out
==6001==
Enter the expression:
5 ^ (3 ^ 2)
Expression tree:
        5.00
^
                3.00
        ^
                2.00
Tree size: 5

Prefix traversal: ^ 5.00 ^ 3.00 2.00
Infix traversal: 5.00 ^ 3.00 ^ 2.00
Postfix traversal: 5.00 3.00 2.00 ^ ^
-----
Original expression: (5.00 ^ (3.00 ^ 2.00))
Simplified expression: (5.00 ^ (3.00 ^ 2.00))
Tree size: 5
        5.00
^
                3.00
        ^
                2.00
-----
Result: 1953125.00
==6001==
==6001== HEAP SUMMARY:
==6001==     in use at exit: 0 bytes in 0 blocks
==6001==   total heap usage: 7 allocs, 7 frees, 2,248 bytes allocated
==6001==
==6001== All heap blocks were freed -- no leaks are possible
==6001==
==6001== For lists of detected and suppressed errors, rerun with: -s
==6001== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

## 9. Дневник отладки

| **№** | **Лаб.Или Дом.** | **Дата** | **Время** | **Событие** | **Действие по исправлению** | **Примечание** |
| --- | --- | --- | --- | --- | --- | --- |
| **1** | **Дом.** | **27.05.23** | **13:00** | **Выполнение лабораторной работы** | **-** | **-** |

## 10. Замечания автора по существу работы
[Защита с олимпроги](https://mai2022.contest.codeforces.com/group/Ej1bTQMkro/contest/427391/submission/198815245)

[Дорешка](https://mai2022.contest.codeforces.com/group/Ej1bTQMkro/contest/427391/submission/207096684)

## 11. Выводы

В ходе выполнения данной лабораторной работы было изучено построение дерева выражений. Были выполнены функции удаления произведений с нулевым сомножителем и удаления нулевого слагаемого. Также было рассмотрено использование бинарного минуса.

<b>Подпись студента:</b> ___________

