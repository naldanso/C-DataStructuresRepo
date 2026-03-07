#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_


typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct BST {
    Node* root;
    int size;
} BST;

//returns an initialized tree
BST* initializeTree();

//destroys a tree
void destroyTree(BST* tree);

//create tree node
void addNode(const int num, BST* tree);

//get data from tree
int getData(const int num, const BST* const tree);

//delete node from tree
void deleteData(const int num, BST* tree);

#endif
