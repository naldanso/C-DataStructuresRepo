#include "binarysearchtree.h"
#include <time.h>

int main(){
    printf("initializing tree...\n");
    BST* tree1 = initializeTree();

    srand(time(NULL));

    for(int i = 0; i < 10; i++){
        //numbers 1...20
        int num = rand() % 20;
        printf("adding %d to tree...\n", num);
        addNode(num, tree1);
    }

    return 0;
}
