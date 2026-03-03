#ifndef SINGLELINKEDLIST_H_
#define SINGLELINKEDLIST_H_

//the Node unit
typedef struct Node {
    int data;
    struct Node* next;
} Node;

//the linked list that holds Nodes
typedef struct singleLinkedList {
  Node* head;
  int size;
} singleLinkedList;

//creates a node
void createData(const int num, singleLinkedList* list);

//retrieves data at given index
int getData(const int num, singleLinkedList* list);

//updates data at given index
void setData(const int num, const int pos, singleLinkedList* list);

//deletes a node at a given index
void deleteData(const int num, singleLinkedList* list);

//frees up memory allocated by the list
void destroyList(singleLinkedList* list);

#endif
