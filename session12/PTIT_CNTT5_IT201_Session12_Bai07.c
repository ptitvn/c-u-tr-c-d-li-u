#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev; 
} Node;
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Khong the cap phat bo nho!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL; 
    return newNode;
}
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d<->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
void addNodeAtEnd(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    
    current->next = newNode;
    newNode->prev = current;
}
void sortList(Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return; 
    }
    
    Node* current;
    Node* nextNode;
    int temp;
    
    for (current = *head; current != NULL; current = current->next) {
        for (nextNode = current->next; nextNode != NULL; nextNode = nextNode->next) {
            if (current->data > nextNode->data) {
                
                temp = current->data;
                current->data = nextNode->data;
                nextNode->data = temp;
            }
        }
    }
}
int main() {
    Node* head = createNode(5);
    addNodeAtEnd(&head, 4);
    addNodeAtEnd(&head, 3);
    addNodeAtEnd(&head, 2);
    addNodeAtEnd(&head, 1);
    addNodeAtEnd(&head, 6);

    printf("Danh sach lien ket truoc khi sap xep:\n");
    printList(head);

    sortList(&head);

    printf("Danh sach lien ket sau khi sap xep:\n");
    printList(head);

    Node* current = head;
    Node* temp;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}