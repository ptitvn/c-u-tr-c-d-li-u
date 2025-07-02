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
    printf("\n");
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

    // Tạo danh sách liên kết với 5 phần tử bất kỳ
    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    append(&head, 40);
    append(&head, 50);

    // In danh sách liên kết
    printf("Danh sach lien ket: ");
    printList(head);

    // Giải phóng bộ nhớ
    freeList(head);

    return 0;
}