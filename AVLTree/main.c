#include "avltree.h"
#include <time.h>

int main(){

    //initialize tree
    AVL* tree1 = initialize();
    printf("AVL tree1 initialized; root = %p, size = %d", tree1->root, tree1->size);

    printf("running insertion test...\n");
    //populate tree; tests balancing and insertion
    int num = 0;
    for(int i = 0; i < 100; i++){
        num = rand() % 101; //0...100
        insertNode(num, tree1);
    }
    printf("insertion tests passed\n\n");

    printf("running retrieval test...\n");
    int fish = 0; //retrieval var

    //get tree; tests retrieval
    for(int i = 0; i < 100; i++){
        num = rand() % 101; //0...100
        fish = getNode(num, tree1);
    }
    printf("retrieval tests passed\n\n");

    //destroy tree
    printf("destroying tree...\n");
    destroyTree(tree1);
    printf("tree successfully destroyed\n\n");

    return 0;
}
