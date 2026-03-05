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
void initializeTree(BST* tree);

//destroys a tree
void destroyTree(BST* tree);

//create tree node
void addNode(int data, BST* tree);

//get data from tree
int getData(BST* tree);

//update tree node
void setData(BST* tree);

//delete node from tree
void deleteData(BST* tree);

#endif
