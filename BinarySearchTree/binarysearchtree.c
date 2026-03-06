#include "binarysearchtree.h"

//initializes tree
void initializeTree(BST* tree){
    tree = (BST*)malloc(sizeof(BST));
    tree->root = NULL;
    tree->size = 0;
    
    assert(tree->root == NULL);
    assert(tree->size == 0);

    printf("list initialized with root = NULL, size = %d", tree->size);
}

//destroys a tree
void destroyTree(BST* tree){
    //edge case: tree is already empty
    if(!tree->root){
        free(tree);
        tree = NULL;
    }
    
    //edge case: one node
    else if(!tree->root->left || !tree->root->left){
        free(tree->root);
        tree->root = NULL;
    }
    tree = NULL;
    assert(tree == NULL);

    printf("tree successfully destroyed");
}

//create tree node
void addNode(const int num, BST* tree){
    //error: uninitialized tree
    if(!tree){
        printf("tree is uninitialized; returning");
        return;
    }

    //edge case: tree root is null
    if(!tree->root){
        tree->root = (Node*)malloc(sizeof(Node));
        tree->root->data = num;
    }
    //tree root is not null 
    else{
        //left logic
        if(num < tree->root->data){
            //null case; simple malloc
            if(!tree->root->left){
                tree->root->left = (Node*)malloc(sizeof(Node));
                tree->root->left->data = num;
            }
            else{
                //helper function
            }
        }
        //right logic
        if(num > tree->root->data){
            //null case; simple malloc
            if(!tree->root->right){
                tree->root->right = (Node*)malloc(sizeof(Node));
                tree->root->right->data = num;
            }
            else{
                //helper function
            }
        }
    }

    tree->size++;
    printf("node added: tree size is now %d", tree->size);
}

//get data from tree
int getData(const int num, const BST* const tree){
    return 0;
}

//delete node from tree
void deleteData(const int num, BST* tree){

}
