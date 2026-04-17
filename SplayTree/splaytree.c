#include "splaytree.h"
#include <assert.h>
/****************
 * CONSTANTS
 * *************/
int GET_ERROR = -1;

/********************
 * END OF CONSTANTS
 * *****************/

/********************
 * HELPER FUNCTIONS
 * ******************/
void destroyHelper(Node* node, Splay* tree){ //helper for de-allocation
    if(node->left){ //check left
        destroyHelper(node->left, tree);
    }
    if(node->right){ //check right
        destroyHelper(node->right, tree);
    }

    free(node); //free memory, dock pointers
    tree->size--;
    node = NULL;
}

int getHelper(const int num, const Node* const node){ //retrieval helper
    if(!node){ //hit null
        return GET_ERROR;
    }

    if(num < node->key){ //check left
        return getHelper(num, node->left);
    }
    if(num > node->key){ //check right
        return getHelper(num, node->right);
    }

    return node->key; //data was found
}

Node* insertHelper(const int num, Node* node, Splay* tree){
    if(!node){ //hit null, insert node
        node = (Node*)calloc(1, sizeof(Node));
        node->key = num;
        tree->size++;
        return node;
    }

    if(num < node->key){ //check left
        node->left = insertHelper(num, node->left, tree);
    }
    if(num > node->key){ //check right
        node->right = insertHelper(num, node->right, tree);
    }

    return node; //returning the node, but really returning the subtree

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

    if(tree->root->left){ //check left
        destroyHelper(tree->root->left, tree);
    }
    if(tree->root->right){ //check right
        destroyHelper(tree->root->right, tree);
    }

    free(tree->root); //free memory and dock pointers
    tree->size--;
    tree->root = NULL;
    tree = NULL;
    assert(tree->size == 0);
}

int get(const int num, const Splay* const tree){ //retrieval function
    if(!tree || !tree->root){ //tree or root null check
        return GET_ERROR;
    }

    if(num < tree->root->key){ //check left
        return getHelper(num, tree->root->left);
    }
    if(num > tree->root->key){ //check right
        return getHelper(num, tree->root->right);
    }

    return tree->root->key; //found value at root, no splay required
}

void insert(const int num, Splay* tree){ //insert function
    if(!tree){ //no tree found
        return;
    }

    if(!tree->root){ //no root exists; insert and exit
        tree->root = (Node*)calloc(1, sizeof(Node));
        tree->size++;
        tree->root->key = num;
        return;
    }
    if(num < tree->root->key){ //check left
        tree->root->left = insertHelper(num, tree->root->left, tree);
    }
    if(num > tree->root->key){ //check right
        tree->root->right = insertHelper(num, tree->root->right, tree);
    }

}
/************************
 * END OF MAIN FUNCTIONS
 * **********************/
