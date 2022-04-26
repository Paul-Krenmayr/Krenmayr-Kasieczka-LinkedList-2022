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
    printf("finish\n");
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
        return sizeof(int);
    }

    newHead = (*head)->next;
    value = (*head)->data;
    free(*head);
    *head = newHead;

    return value;
}

int removeLastItem(Node *head){
    int value;
    Node *secondLast = head;
    if(head->next == NULL){
        value = head ->data;
        free(head);
        return value;
    }
    /*Erhält das vorletzte Item*/
    while (secondLast->next->next != NULL){
        secondLast = secondLast->next;
    }

    /*Löscht das letzte Item*/
    value = secondLast->next->data;
    free(secondLast->next);
    secondLast->next = NULL;

    return value;
}
int removeByIndex(Node** head, int index){
    int value = sizeof(int);
    Node* current = *head;
    Node* temp;

    /*Return das Erste Item */
    if (index == 0){
        return removeFirstItem(head);
    }
    /*Geht zu der Stelle vor der richtigne Stelle in der Liste*/
    for (int i = 0; i < index-1; ++i) {
        if(current->next == NULL){
            return sizeof(int);
        }
        current = current->next;
    }

    if (current->next == NULL){
        return sizeof(int);
    }
    /*Kürzt die Liste an der Richtigen stelle*/
    temp = current->next;
    value = temp->data;
    current->next = temp->next;
    free(temp);

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
    addItemEnd(12345,head);
    addItemEnd(12,head);
    printList(head);
    removeFirstItem(&head);
    printList(head);
    removeLastItem(head);
    printList(head);
    removeByIndex(&head, 3);
    printList(head);
    return 0;
}