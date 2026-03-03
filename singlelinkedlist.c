#include <stdio.h>
#include <stdlib.h>
#include "singlelinkedlist.h"

/*This is the file that implements what's in
 * singlelinkedlist.h.
 */

//initializes a singly linked list
singleLinkedList* initializeList(){
    singleLinkedList* list = (singleLinkedList*)malloc(sizeof(singleLinkedList));

    list->head = NULL;
    list->size = 0;
    printf("list initialized with head = NULL, size = %d\n\n", list->size);
    return list;
}
//creates a node
void createData(const int num, singleLinkedList* list){
    //edge case: empty list
    if(list->size == 0){
        list->head = (Node*)malloc(sizeof(Node));
        list->head->data = num;
        list->head->next = NULL;
    }
    //standard append
    else{
        Node* ptr = list->head;

        while(ptr->next != NULL){
            ptr = ptr->next;
        }

        ptr->next = (Node*)malloc(sizeof(Node));
        ptr->next->data = num;
        ptr->next->next = NULL;
    }

    list->size++;
    printf("createData passed: list size is now %d \n\n", list->size);
}

//retrieves data at given index
int getData(const int num, singleLinkedList* list){
    Node* ptr = list->head;

    while(ptr != NULL){
        if(ptr->data == num){
            printf("retrieved %d \n\n", ptr->data);
            return ptr->data;
        }
        ptr = ptr->next;
    }
    //no data was found
    printf("getData passed, but no data was found\n\n");
    return 0;
}

//updates data at given index
void setData(const int num, const int pos, singleLinkedList* list){
    Node* ptr = list->head;
    int i = 0;

    while(ptr != NULL){
        if(i == pos){
            ptr->data = num;
            printf("index %d set to %d \n\n", pos, ptr->data);
            return;
        }
        ptr = ptr->next;
    }
}

//deletes a node at a given index
void deleteData(const int num, singleLinkedList* list){
    //edge case: empty list
    if(list->size == 0){
        printf("list is empty\n\n");
        return;
    }

    Node* curr = list->head;

    //edge case: beginning of list
    if(curr->data == num){
        list->head = curr->next;
        free(curr);
        list->size--;
        printf("deletaData passed\n\n");
        return;
    }

    curr = curr->next;
    Node* prev = list->head;
    
    while(curr != NULL){
        if(curr->data == num){
            //edge case: end of list
            if(curr->next == NULL){
                prev->next = NULL;
                free(curr);
                list->size--;
                printf("deleteData passed\n\n");
                return;
            }
            //the node is a middle piece
            else{
                prev->next = curr->next;
                free(curr);
                list->size--;
                printf("deleteData passed\n\n");
                return;
            }
        }
        curr = curr->next;
    }
    printf("deleteData passed, but nothing deleted\n\n");
}

//frees up memory allocated by the list
void destroyList(singleLinkedList* list){
    Node* curr = list->head;

    while(curr != NULL){
        list->head = list->head->next;
        free(curr);
        curr = list->head;
    }
    free(list);
    printf("destroyList passed\n\n");
}
