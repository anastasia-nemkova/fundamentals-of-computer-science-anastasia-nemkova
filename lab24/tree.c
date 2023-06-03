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