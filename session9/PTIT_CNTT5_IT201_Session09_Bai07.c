#include <stdio.h>
#include <stdlib.h>
/*
Từ dữ liệu đã tạo từ bài 1, xây dựng thêm hàm thêm mới phần tử vào vị trí bất kỳ
Yêu cầu người dùng nhập vào giá trị và vị trí muốn thêm
 Thêm phần tử có dữ liệu là giá trị đã nhập vào vị trí muốn thêm trong danh sách liên kết
Input

Output

1->2->3->4->5->NULL

value: 7

position: 2

 

1->7->2->3->4->5->NULL

*/
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

    // Tạo danh sách liên kết với 5 phần tử bất kỳ
    for (int i = 1; i <= 5; i++) {
        insertAtPosition(&head, i, i);
    }

    // In danh sách liên kết
    printf("Danh sach lien ket: ");
    printList(head);

    // Nhập giá trị và vị trí muốn thêm
    int value, position;
    printf("Nhap gia tri muon them: ");
    scanf("%d", &value);
    printf("Nhap vi tri muon them (bat dau tu 1): ");
    scanf("%d", &position);

    // Thêm phần tử vào vị trí đã chỉ định
    insertAtPosition(&head, value, position);

    // In danh sách liên kết sau khi thêm
    printf("Danh sach lien ket sau khi them: ");
    printList(head);

    // Giải phóng bộ nhớ
    freeList(head);

    return 0;
}