#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct LinkedList {
    Node *head;
    Node *tail;
    int size;
} LinkedList;

LinkedList* init() {
    
    LinkedList *list = (LinkedList *) malloc(sizeof(LinkedList));
    list->head = NULL; 
    list->tail = NULL;
    list->size = 0;
    return list;
}

void add(LinkedList *list, int data) {

    // alocates memory for a new node
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;


    if (list->head == NULL) {
        list->head = newNode;
    } else {
        list->tail->next = newNode;
    }
    if (list->tail != NULL) {
        list->tail = newNode;
    }
    list->size++;
}

int get(LinkedList *list, int index) {

    if (index >= list->size) {
        printf("Index out of bounds\n");
        return -1;
    }

    if (index == 0) {
        return list->head->data;
    }

    if (index == list->size - 1) {
        return list->tail->data;
    }

    Node *current = list->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }

    return current->data;
}

int getSize(LinkedList *list) {
    return list->size;
}

