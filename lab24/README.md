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
    return (c == '+'||  c == '-' || c == '*' || c == '/');
}

int getOperatorPriority(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else
        return 0;
}

int isUnaryMinus(const char* infix, int index) {
    if (index == 0){
        return 1;
    }
    char prevChar = infix[index - 1];
    printf("'PREVCHAR'%d %d\n", index, prevChar);
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
            while (top >= 0 && stack[top] != '(' && getOperatorPriority(stack[top]) >= getOperatorPriority(c)) {
                postfix[postfixIndex++] = stack[top--];
                postfix[postfixIndex++] = ' ';
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
        
        if(root->nodeUnion.op.right->nodeUnion.value == 0 && root->nodeUnion.op.left->nodeUnion.value == 0){
            free(root);
            return createValueNode(0.0);
        }

        if (root->nodeUnion.op.op == '*') {

            if (root->nodeUnion.op.left->nodeType == VALUE && root->nodeUnion.op.left->nodeUnion.value == 0.0) {
                free(root);
                return createValueNode(0.0);
            }
            
            if (root->nodeUnion.op.right->nodeType == VALUE && root->nodeUnion.op.right->nodeUnion.value == 0.0) {
                free(root);
                return createValueNode(0.0);
            }
        //Удаляем лишние нули
        } else if(root->nodeUnion.op.op == '+'){
            if (root->nodeUnion.op.left->nodeType == VALUE && root->nodeUnion.op.left->nodeUnion.value == 0.0){
                Node *right = root->nodeUnion.op.right;
                free(root);
                *root = *right;
                free(right);
            }
            if (root->nodeUnion.op.right->nodeType == VALUE && root->nodeUnion.op.right->nodeUnion.value == 0.0){
                Node *left = root->nodeUnion.op.left;
                free(root);
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

int main(void) {
   
    char infixExpression[NODES_LENGTH];
    printf("Enter the expression:\n");
    fgets(infixExpression, sizeof(infixExpression), stdin);
    infixExpression[strcspn(infixExpression, "\n")] = '\0';
    printf("%s\n", infixExpression);
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
    
    deleteExpressionTree(expressionTree);
    
    return 0;
}
  ```
        
## 8. Распечатка протокола



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

