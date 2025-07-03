#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
int main (){
    Node* head = createNode(5);
    head->next = createNode(4);
    head->next->next = createNode(3);
    head->next->next->next = createNode(2);
    head->next->next->next->next = createNode(1);

    printf("Danh sach lien ket: ");
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("->NULL\n");

    // Tìm phần tử nằm giữa danh sách liên kết
    int count = 0;
    current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }

    int middleIndex = count / 2; 
    current = head;
    for (int i = 0; i < middleIndex; i++) {
        current = current->next;
    }
    
    printf("Node %d: %d\n", middleIndex + 1, current->data);

    // Thêm phần tử mới vào cuối danh sách
    Node* newNode = createNode(6);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* last = head;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = newNode;
    }

    printf("Danh sach lien ket sau khi them: ");
    current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    
    count++;
    middleIndex = count / 2; 
    current = head;
    for (int i = 0; i < middleIndex; i++) {
        current = current->next;
    }
    
    printf("\nNode %d: %d\n", middleIndex + 1, current->data);

    current = head;
    Node* temp;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}