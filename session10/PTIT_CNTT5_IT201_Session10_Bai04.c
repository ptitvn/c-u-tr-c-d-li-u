#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;
// Hàm tạo nút mới
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Khong the cap phat bo nho!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
// Hàm xóa phần tử cuối cùng trong danh sách liên kết
void deleteLastNode(Node** head_ref) {
    if (*head_ref == NULL) {
        return; 
    }
    
    Node* current = *head_ref;
    
    if (current->next == NULL) {
        free(current);
        *head_ref = NULL;
        return;
    }
    
    while (current->next->next != NULL) {
        current = current->next;
    }
    
    free(current->next);
    current->next = NULL;
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

    deleteLastNode(&head);

    printf("Danh sach lien ket sau khi xoa phan tu cuoi cung: ");
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
