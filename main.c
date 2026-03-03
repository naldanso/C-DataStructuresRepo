#include <stdio.h>
#include "singlelinkedlist.h"

int main(){
    singleLinkedList list1;
    createData(5, list1);
    createData(6, list1);
    setData(1, 7, list1);
    deleteData(7, list1);

    destroyList(list1);
    return 0;
}
