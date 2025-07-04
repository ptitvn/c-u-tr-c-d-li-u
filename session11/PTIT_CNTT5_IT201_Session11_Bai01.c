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
int main() {
    
    Node* head = createNode(10);
    Node* second = createNode(20);
    Node* third = createNode(30);
    Node* fourth = createNode(40);
    Node* fifth = createNode(50);

    // Kết nối các phần tử
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;
    fourth->next = fifth;
    fifth->prev = fourth;

    Node* current = head;
    printf("Danh sach lien ket doi gom cac phan tu: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    
    current = head;
    Node* temp;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}