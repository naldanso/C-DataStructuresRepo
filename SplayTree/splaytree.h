#ifndef SPLAYTREE_H_
#define SPLAYTREE_H_

#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct Splay {
    Node* root;
    int size;
} Splay;

Splay* initialize(); //initializes splay
void destroyTree(Splay* tree); //de-allocates tree
void insert(const int num, Splay* tree); //insertion
int get(const int num, const Splay* const tree); //retrieval

#endif
