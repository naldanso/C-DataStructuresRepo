#include "minskewheap.h"
#include <time.h>

int main(){
    //initialization test
    MSH* heap1 = initialize();

    //insertion test
    for(int i = 0; i < 1000; i++){
        insert(rand() % 1001, heap1);
    }

    //extraction test
    int key;
    for(int i = 0; i < 100; i++){
        key = extractTop(heap1);
        assert(key > -1);
    }

    //destruction test
    destroyHeap(heap1);

    return 0;
}
