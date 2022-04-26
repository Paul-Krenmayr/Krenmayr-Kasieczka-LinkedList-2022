#include <stdio.h>
#include <malloc.h>

/**/
typedef struct node {
    int data;
    struct node * next;
} Node;

void printList(Node* head){
    Node *current = head;

    while(current != NULL){
        printf("%d",current->data);
        current = current->next;
    }
}

void addItem(int item,Node* head){
    Node *current = head;
    /*Getting to the last item*/
    while (current != NULL) {
        current = current->next;
    }

    /*Adding New Item*/
    current->next = (Node *) malloc(sizeof(Node));
    current->next->data = item;
    current->next->next = NULL;

}

int main() {
    Node *head = NULL;

    head = (Node *) malloc(sizeof(Node));

    if (head == NULL) {
        return 1;
    }

    head->data = 1;
    head->next = NULL;

    addItem(5,head);
    printList(head);
    return 0;
}



