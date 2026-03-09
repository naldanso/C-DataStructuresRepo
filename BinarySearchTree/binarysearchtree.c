/* this is the file that implements
 * binarysearchtree.h.
 */

#include "binarysearchtree.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* Start of Helper Section */

//helper for tree node insertion/retrieval
Node* traverse(const int num, Node* node){

}

/* End of Helper Section */

/* Start of Main Function Section */

//initializes tree
BST* initializeTree(){
    BST* tree = (BST*)calloc(1, sizeof(BST));
    //tree->root = NULL;
    //tree->size = 0;
    
    assert(tree->root == NULL);
    assert(tree->size == 0);

    printf("list initialized with root = NULL, size = %d", tree->size);
    return tree;
}

//destroys a tree
void destroyTree(BST* tree){
    //error: tree itself is null
    if(!tree){
       printf("destroyTree: nothing to free\n\n"); 
    }

    //edge case: tree is already empty
    if(!tree->root){
        free(tree);
    }
    //edge case: only root node
    else if(!tree->root->left || !tree->root->left){
        free(tree->root);
        tree->root = NULL;
    }

    //TODO: implement subtree destruction

    tree = NULL;
    assert(tree == NULL);

    printf("destroyTree: tree successfully destroyed\n\n");
}

//create tree node
void addNode(const int num, BST* tree){
    //error: uninitialized tree
    if(!tree){
        printf("addNode: tree is uninitialized; returning\n\n");
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
    //TODO
    return 0;
}

//delete node from tree
void deleteData(const int num, BST* tree){
    //TODO
}

/* End of Main Function Section */
