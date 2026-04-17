#include "splaytree.h"
#include <time.h>

int main(){

    //initialize test
    printf("running initialization test...\n");
    Splay* tree1 = initialize();
    printf("initialization passed\n\n");

    //insertion test
    printf("running insertion test...\n");

    for(int i = 0; i < 1001; i++){
        int rnum = rand() % 1001; //0...1000
        insert(rnum, tree1);
    }

    printf("insertions passed\n\n");

    //retrieval test
    printf("running retrieval test...\n");
    int fish = 0; //retrieval var

    for(int i = 0; i < 1001; i++){
        int rnum = rand() % 1001; //0...1000
        fish = get(rnum, tree1);
    }

    printf("retrievals passed\n\n");

    //destruction test
    printf("destroying tree...\n");
    destroyTree(tree1);
    printf("tree destruction passed\n\n");
    return 0;
}
