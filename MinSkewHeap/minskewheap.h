#ifndef MIN_SKEW_HEAP_H
#define MIN_SKEW_HEAP_H

typedef struct Node { //heap nodes
    int key;
    struct Node* left;
    struct Node* right;
} Node;

typedef struct MSH { //min-skew heap
    struct Node* heap; //heap root
    int size; //heap size
}

MSH* initialize(); //initialize heap
int extractTop(MSH* heap); //extracts root, merges subtrees
void insert(const int num, MSH* heap); //insert into heap
void destroyHeap(MSH* heap); //deallocates heap

#endif
