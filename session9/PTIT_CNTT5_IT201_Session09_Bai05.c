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
// Hàm thêm phần tử vào đầu danh sách liên kết
void prepend(Node** head_ref, int new_data) {
    Node* new_node = createNode(new_data);
    new_node->next = *head_ref;
    *head_ref = new_node;
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

    prepend(&head, 5);
    prepend(&head, 4);
    prepend(&head, 3);
    prepend(&head, 2);
    prepend(&head, 1);

    printf("Danh sach lien ket: ");
    printList(head);

    printf("Duyet toan bo danh sach lien ket:\n");
    traverseList(head);

    int new_data;
    printf("Nhap so nguyen duong can them vao dau danh sach: ");
    scanf("%d", &new_data);
    
    prepend(&head, new_data);

    printf("Danh sach lien ket sau khi them phan tu moi: ");
    printList(head);

    freeList(head);

    return 0;
}
