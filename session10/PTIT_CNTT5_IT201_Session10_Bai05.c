#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;
//// Hàm tạo nút mới
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
// Hàm xóa phần tử có dữ liệu xác định
void deleteNode(Node** head_ref, int value) {
    Node* current = *head_ref;
    Node* prev = NULL;

    while (current != NULL) {
        if (current->data == value) {
            if (prev == NULL) {
                *head_ref = current->next;
            } else {
                prev->next = current->next;
            }
            Node* temp = current;
            current = current->next;
            free(temp);
        } else {
            prev = current;
            current = current->next;
        }
    }
}
int main (){
    Node* head = createNode(5);
    head->next = createNode(4);
    head->next->next = createNode(3);
    head->next->next->next = createNode(5);
    head->next->next->next->next = createNode(2);
    head->next->next->next->next->next = createNode(1);
    head->next->next->next->next->next->next = createNode(5);

    printf("Danh sach lien ket: ");
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("->NULL\n");

    int value;
    printf("Nhap so nguyen duong can xoa: ");
    scanf("%d", &value);

    deleteNode(&head, value);

    printf("Danh sach lien ket sau khi xoa: ");
    current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("->NULL\n");

    current = head;
    Node* temp;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}