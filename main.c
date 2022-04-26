#include <stdio.h>
#include <malloc.h>

/*The new Node DataType*/
typedef struct node {
    int data;
    struct node * next;
} Node;

void printList(Node* head){
    Node *current = head;

    while(current != NULL){
        printf("%d\n",current->data);
        current = current->next;
    }
}
void addItemBeginning(int item,Node** head){
    Node* newHead;
    newHead = (Node *) malloc(sizeof (Node));

    newHead->data = item;
    newHead->next = *head;
    *head = newHead;
}

int addItemEnd(int item, Node* head){
    Node *current = head;

    /*Getting to the last item*/
    while (current->next != NULL) {
        current = current->next;
    }

    /*Adding New Item*/
    current->next = (Node *) malloc(sizeof(Node));
    current->next->data = item;
    current->next->next = NULL;

    return 0;
}
int removeFirstItem(Node** head){
    int value;
    Node *newHead;
    if(*head == NULL){
        return -sizeof(int);
    }

    newHead = (*head)->next;
    value = (*head)->data;
    free(*head);
    *head = newHead;

    return value;
}
int removeLastItem(Node *head){
    int value;
    Node *last;
    Node *secondLast;
    if(head->next == NULL){
        value = head ->data;
        free(head);
        return value;
    }
    while (last->next != NULL){
        secondLast =last;
        last = last->next;
    }
    value = last->data;
    secondLast->next = NULL;
    free(last);
    return value;
}

int main() {
    Node *head = NULL;

    head = (Node *) malloc(sizeof(Node));

    if (head == NULL) {
        return 1;
    }

    head->data = 1;
    head->next = NULL;

    addItemBeginning(3,&head);
    addItemEnd(5, head);
    printList(head);
    removeFirstItem(&head);
    printList(head);
    return 0;
}