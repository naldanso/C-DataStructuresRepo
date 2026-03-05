#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct BST {
    Node* root;
    int size;
} BST;

//initializes a tree
void initializeTree(BST* tree){
    tree = (BST*)malloc(sizeof(BST));
    tree->root = NULL;
    tree-size = 0;
    
    assert(tree->root == NULL);
    assert(tree->size == 0);

    printf("list initialized with root = NULL, size = %d", list->size);
}

//destroys a tree

//create tree node

//get data from tree

//update tree node

//delete node from tree

#endif
