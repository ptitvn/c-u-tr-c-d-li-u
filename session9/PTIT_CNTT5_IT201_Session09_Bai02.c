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
// Hàm in danh sách liên kết
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("->NULL\n");
}
// Hàm duyệt toàn bộ danh sách liên kết và in dữ liệu của từng phần tử
void traverseList(Node* head) {
    Node* current = head;
    int index = 1; 
    while (current != NULL) {
        printf("Node %d: %d\n", index, current->data);
        current = current->next;
        index++;
    }
}
// Hàm thêm phần tử vào cuối danh sách liên kết
void append(Node** head_ref, int new_data) {
    Node* new_node = createNode(new_data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}
// Hàm giải phóng bộ nhớ của danh sách liên kết
void freeList(Node* head) {
    Node* current = head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}
int main() {
    Node* head = NULL;

    
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);

    printf("Danh sach lien ket: ");
    printList(head);

    traverseList(head);

    freeList(head);

    return 0;
}