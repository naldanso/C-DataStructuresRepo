#include "avltree.h"
#include <time.h>

int main(){

    //initialize tree
    AVL* tree1 = initialize();

    //populate tree; tests balancing and insertion
    int num = 0;
    for(int i = 0; i < 100; i++){
        num = rand() % 101; //0...100
        insertNode(num, tree1);
    }

    //get tree; tests retrieval
    for(int i = 0; i < 100; i++){
        num = rand() % 101; //0...100
        printf("retrieving %d\n", num);
        fish = getNode(num, tree1);
    }

    //destroy tree
    printf("destroying tree...\n");
    destroyTree(tree1);

    return 0;
}
