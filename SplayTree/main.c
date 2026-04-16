#include "splaytree.h"
#include <time.h>

int main(){
    //initialize test
    printf("running initialization test...\n");
    Splay* tree1 = initialize();
    printf("initialization passed\n\n");

    //insertion test

    //retrieval test
    //destruction test
    printf("destroying tree...\n");
    destroyTree(tree1);
    printf("tree destruction passed\n\n");
    return 0;
}
