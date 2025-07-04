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
void deleteNodeAtPosition(Node** head, int position) {
    if (*head == NULL || position < 1) {
        printf("Danh sach rong hoac vi tri khong hop le!\n");
        return;
    }
    
    Node* current = *head;
    
    if (position == 1) {
        *head = current->next; 
        if (*head != NULL) {
            (*head)->prev = NULL; 
        }
        free(current);
        return;
    }
    
    for (int i = 1; current != NULL && i < position; i++) {
        current = current->next;
    }
    
    if (current == NULL) {
        printf("Vi tri vuot qua danh sach!\n");
        return;
    }
    
    if (current->prev != NULL) {
        current->prev->next = current->next;
    }
    
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    
    free(current);
}
int main() {
    Node* head = createNode(1);
    Node* second = createNode(2);
    Node* third = createNode(3);
    Node* fourth = createNode(4);
    Node* fifth = createNode(5);

    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;
    fourth->next = fifth;
    fifth->prev = fourth;

    printList(head);

    int position;
    printf("Nhap vi tri muon xoa: ");
    scanf("%d", &position);

    deleteNodeAtPosition(&head, position);

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