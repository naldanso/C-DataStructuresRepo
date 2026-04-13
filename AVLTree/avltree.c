#include "avltree.h"
#include <assert.h>

/************
 * CONSTANTS
 * *********/
const int GET_ERROR = -1; //sentinel value for data not found

/******************
 * END OF CONSTANTS
 * ****************/

/*******************
 * HELPER SECTION 
 * *****************/
void destroyHelper(Node* node, AVL* tree){ //helper for deallocation
    if(node->left){ //check left
        destroyHelper(node->left, tree);
    }
    if(node->right){ //check right
        destroyHelper(node->right, tree);
    }

    free(node); //free memory! null-dock the pointers too
    tree->size--;
    node = NULL;
}

int getNodeHelper(const int num, const Node* const node){ //helper for retrieval
    if(!node){ //we're at NULL, return error
        return GET_ERROR;
    }
    if(num < node->data){ //check left
        return getNodeHelper(num, node->left);
    }
    if(num > node->data){ //check right
        return getNodeHelper(num, node->right);
    }
    return node->data; //found our data
}

Node* insertNodeHelper(const int num, Node* node, AVL* tree){
    if(!node){ //value doesn't exist, create new node
        node = (Node*)calloc(1, sizeof(Node));
        node-> data = num;
        tree->size++;
        return node;
    }
    if(num < node->data){ //check left
        node->left = insertNodeHelper(num, node->left, tree);
    }
    else if(num > node->data){ //check right
        node->right = insertNodeHelper(num, node->right, tree);
    }

    return node; //value already exists, or completed left/right check
}
/************************
 * END OF HELPER SECTION 
 * **********************/ 


/* ***************
 * MAIN FUNCTIONS
 * ***************/
AVL* initialize(){ //initialize the tree
    return (AVL*)calloc(1, sizeof(AVL)); 
}

void destroyTree(AVL* tree){ //destroying with post-order traversal
    if(tree->root->left){ //check left
        destroyHelper(tree->root->left, tree);
    }
    if(tree->root->right){ //check right
        destroyHelper(tree->root->right, tree);
    }

    free(tree->root); //free memory.
    tree->size--;
    assert(tree->size == 0); //assert all nodes are gone
    tree->root = NULL; //null dock the pointer
}

int getNode(const int num, const AVL* const tree){ //retrieves node of specified value
    if(!tree || !tree->root){ // tree or root doesn't exist
        printf("no tree to retrieve from; returning -1");
        return GET_ERROR;
    }
    if(num < tree->root->data){ //check left
       return getNodeHelper(num, tree->root->left);
    }
    if(num > tree->root->data){ //check right
        return getNodeHelper(num, tree->root->right);
    }

    return tree->root->data; //found our data
}

void insertNode(const int num, AVL* tree){ //inserts node of specified value
    if(!tree){ //tree doesn't exist
        printf("insertNode: no tree to insert \n\n");
    }
    if(!tree->root){ //first node to be inserted
        tree->root = (Node*)calloc(1, sizeof(Node));
        tree->root->data = num;
        tree->size++;
    }
    if(num < tree->root->data){ //check left
        tree->root->left = insertNodeHelper(num, tree->root->left, tree);
    }
    if(num > tree->root->data){ //check right
        tree->root->right = insertNodeHelper(num, tree->root->right, tree);
    }
}

/* END OF MAIN FUNCTIONS */ 
