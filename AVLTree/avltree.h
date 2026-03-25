#ifndef AVLTREE_H
#define AVLTREE_H

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
} Node;

typedef struct AVL {
    Node* root;
    int size;
    int height;
} AVL;

AVL* initialize(); //initializes tree
void destroyTree(AVL* tree); //destroys tree
int getNode(const int num, const AVL* const tree); //get data from tree
void insertNode(const int num, AVL* tree); //inserts node to tree

//TODO: height, checkbalance functions etc

#endif
