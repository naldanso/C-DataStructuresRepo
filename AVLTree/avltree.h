#ifndef AVLTREE_H
#define AVLTREE_H

#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
} Node;

typedef struct AVL {
    Node* root; //root node of the tree
    int size; //number of nodes in the tree
    int height;
} AVL;

AVL* initialize(); //initializes tree
void destroyTree(AVL* tree); //destroys tree
int getNode(const int num, const AVL* const tree); //get data from tree
void insertNode(const int num, AVL* tree); //inserts node to tree

//TODO: height, checkbalance functions etc

#endif
