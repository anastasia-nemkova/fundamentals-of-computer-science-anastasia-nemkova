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