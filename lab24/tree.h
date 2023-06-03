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