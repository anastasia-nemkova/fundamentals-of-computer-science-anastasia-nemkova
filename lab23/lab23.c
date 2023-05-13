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
