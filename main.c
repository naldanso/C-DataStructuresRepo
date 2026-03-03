#include <stdio.h>
#include <stdlib.h>
#include "singlelinkedlist.h"

int main(){
    printf("initializing singly linked list\n");
    singleLinkedList* list1 = initializeList();

    printf("calling createData\n");
    createData(5, list1);

    printf("calling creataData\n");
    createData(6, list1);

    printf("calling getData\n");
    getData(6, list1);

    printf("calling setData\n");
    setData(1, 1, list1);

    printf("calling deleteData\n");
    deleteData(7, list1);

    printf("calling destroyList\n");
    destroyList(list1);
    return 0;
}
