#include "binarysearchtree.h"
#include <time.h>

int main(){
    printf("initializing tree...\n");
    BST* tree1 = initializeTree();

    srand(time(NULL));

    //addNode test
    for(int i = 0; i < 10; i++){
        //numbers 1...20
        int num = rand() % 20;
        printf("adding %d to tree...\n", num);
        addNode(num, tree1);
    }
    printf("tree size is now %d.\n\n", tree1->size);

    //getData test
    int fish = 0;
    for(int i = 0; i < 10; i++){
        //nums 1...20
        int num = rand() % 20;
        printf("retrieving %d... ", num);
        fish = getData(num, tree1);
        printf("retrieved %d\n\n", fish);
    }

    printf("destroying tree...\n");
    destroyTree(tree1);
    return 0;
}
