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
// Hàm thêm phần tử vào vị trí bất kỳ trong danh sách liên kết
void insertAtPosition(Node** head_ref, int new_data, int position) {
    Node* new_node = createNode(new_data);
    if (position == 1) {
        new_node->next = *head_ref;
        *head_ref = new_node;
        return;
    }
    
    Node* current = *head_ref;
    for (int i = 1; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }
    
    if (current == NULL) {
        printf("Vi tri khong hop le. Them vao cuoi danh sach.\n");
        free(new_node);
        return;
    }
    
    new_node->next = current->next;
    current->next = new_node;
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

    for (int i = 1; i <= 5; i++) {
        insertAtPosition(&head, i, i);
    }

    printf("Danh sach lien ket: ");
    printList(head);

    int value, position;
    printf("Nhap gia tri muon them: ");
    scanf("%d", &value);
    printf("Nhap vi tri muon them (bat dau tu 1): ");
    scanf("%d", &position);

    insertAtPosition(&head, value, position);

    printf("Danh sach lien ket sau khi them: ");
    printList(head);

    freeList(head);

    return 0;
}