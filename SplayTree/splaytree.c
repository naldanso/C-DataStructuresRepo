#include "splaytree.h"
#include <assert.h>

/********************
 * HELPER FUNCTIONS
 * ******************/
void destroyHelper(Node* node, Splay* tree){
    if(node->left){
        destroyHelper(node->left, tree);
    }
    if(node->right){
        destroyHelper(node->right, tree);
    }

    free(node);
    tree->size--;
    node = NULL;
}

int getHelper(const int num, const Node* const node){
    //TODO
}

Node* insertHelper(const int num, Node* node){
    //TODO
}

/**************************
 * END OF HELPER FUNCTIONS
 * ************************/


/******************
 * MAIN FUNCTIONS
 * *****************/
Splay* initialize(){ //initializes tree
    return (Splay*)calloc(1, sizeof(Splay));
}

void destroyTree(Splay* tree){ //de-allocates using postorder traversal
    if(!tree || !tree->root){
        return;
    }
    if(tree->root->left){
        destroyHelper(tree->root->left, tree);
    }
    if(tree->root->right){
        destroyHelper(tree->root->right, tree);
    }

    free(tree->root);
    tree->size--;
    tree->root = NULL;
    assert(tree->size == 0);
}

int get(const int num, const Splay* const tree){ //retrieval function
    //TODO
}

void insert(const int num, Splay* tree){ //insert function
    //TODO
}
/************************
 * END OF MAIN FUNCTIONS
 * **********************/
