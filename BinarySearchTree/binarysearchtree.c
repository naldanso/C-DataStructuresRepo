/* this is the file that implements
 * binarysearchtree.h.
 */

#include "binarysearchtree.h"
#include <assert.h>

/* Start of Helper Section */

//helper for tree node insertion/retrieval
Node* addNodeHelper(const int num, Node* node, BST* tree){
    if(!node){
        node = (Node*)calloc(1, sizeof(Node));
        node->data = num;
        tree->size++;
        return node;
    }

    //check left
    if(num < node->data){
        node->left = addNodeHelper(num, node->left, tree);
    }
    //check right
    else if(num > node->data){
        node->right = addNodeHelper(num, node->right, tree);
    }
    return node;
}

int getDataHelper(const int num, Node* node){
    if(!node){
        printf("getData: value %d doesn't exist\n\n", num);
        return -1;
    }
    //check left
    else if(num < node->data){
        return getDataHelper(num, node->left);
    }
    //check right
    else if(num > node->data){
        return getDataHelper(num, node->right);
    }
    //found the data
    return node->data;
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

    printf("list initialized with root = NULL, size = %d \n\n", tree->size);
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
        tree->root = (Node*)calloc(1, sizeof(Node));
        tree->root->data = num;
        tree->size++;
    }
    //check left
    else if(num < tree->root->data){
        tree->root->left = addNodeHelper(num, tree->root->left, tree);
    }
    //check right
    else if(num > tree->root->data){
        tree->root->right = addNodeHelper(num, tree->root->right, tree);
    }

    printf("addNode: tree size is now %d\n\n", tree->size);
}

//get data from tree
int getData(const int num, const BST* const tree){
    //empty tree
    if(!tree){
        printf("getData: tree uninitialized");
        return 0;
    }
    //empty root
    if(!tree->root){
        printf("getData: root is empty");
        return 0;
    }

    int answer = tree->root->data;
    //check left
    if(num < tree->root->data){
        answer = getDataHelper(num, tree->root->left);
    }
    //check right
    else if(num > tree->root->data){
        answer = getDataHelper(num, tree->root->right);
    }

    return answer;
}

//delete node from tree
void deleteData(const int num, BST* tree){
    //TODO
}

/* End of Main Function Section */
