#include <stdio.h>
#include <malloc.h>

typedef struct node {
    int data;
    struct node * next;
} Node;

Node *head = NULL;
int main() {


    head = (Node *) malloc(sizeof(Node));
    if (head == NULL) {
        return 1;
    }

    head->data = 1;
    head->next = NULL;
    return 0;
}
void printList() {
    Node *current = head;

    while(current != NULL){
        printf()
    }
}