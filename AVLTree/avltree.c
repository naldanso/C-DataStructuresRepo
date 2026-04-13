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

int getNodeHeight(Node* node){ //returns height of given node
    if(!node){ //null is treated as -1; leaf nodes are height 0
        return -1;
    }
    return node->height;
}

void updateHeight(Node* node){ //update height of given node
    int lHeight = getNodeHeight(node->left); //get height of subtrees
    int rHeight = getNodeHeight(node->right);

    if(lHeight > rHeight){ //assign the max between both heights, or they're equal
        node->height = lHeight + 1;
    }
    else{
        node->height = rHeight + 1;
    }
}

int checkBalance(Node* node){ //returns balance factor of given node
    return getNodeHeight(node->left) - getNodeHeight(node->right);
}

Node* leftRotate(Node* node){ //right child becomes new "root"
    Node* temp = node->right;
    Node* temp2 = temp->left;
    temp->left = node;
    node->right = temp2;
    return temp;
}

Node* rightRotate(Node* node){ //left child becomes new "root"
    Node* temp = node->left;
    Node* temp2 = temp->right;
    temp->right = node;
    node->left = temp2;
    return temp;
}

Node* rebalance(Node* node){ //rebalances given node
    int balance = checkBalance(node);
    if(balance > 1){ //left-heavy
       if(checkBalance(node->left) < 0){ //left-right
           node->left = leftRotate(node->left);
       }
       return rightRotate(node);
   }
   else if(balance < -1){ //right-heavy
       if(checkBalance(node->right) > 0){ //right-left 
           node->right = rightRotate(node->right);
       }
       return leftRotate(node);
   }

   return node;
}

Node* insertNodeHelper(const int num, Node* node, AVL* tree){
    if(!node){ //value doesn't exist, create new node
        node = (Node*)calloc(1, sizeof(Node));
        node-> data = num;
        tree->size++;
        return node;
    }
    if(num < node->data){ //check left and rebalance
        node->left = insertNodeHelper(num, node->left, tree);
        updateHeight(node->left);
        node->left = rebalance(node->left);
    }
    else if(num > node->data){ //check right and rebalance
        node->right = insertNodeHelper(num, node->right, tree);
        updateHeight(node->right);
        node->right = rebalance(node->right);
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
        return;
    }
    if(!tree->root){ //first node to be inserted
        tree->root = (Node*)calloc(1, sizeof(Node));
        tree->root->data = num;
        tree->size++;
        return;
    }
    if(num < tree->root->data){ //check left
        tree->root->left = insertNodeHelper(num, tree->root->left, tree);
    }
    else if(num > tree->root->data){ //check right
        tree->root->right = insertNodeHelper(num, tree->root->right, tree);
    }

    //printf("updating root height...\n\n");
    updateHeight(tree->root); //balance tree

    //printf("rebalancing from root...\n\n");
    tree->root = rebalance(tree->root);

    assert(abs(checkBalance(tree->root) <= 1)); //test case
}

/* END OF MAIN FUNCTIONS */ 
