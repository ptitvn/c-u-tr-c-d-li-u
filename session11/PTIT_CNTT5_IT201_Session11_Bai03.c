#include <stdio.h>
#include <stdlib.h>
/*
Từ dữ liệu đã tạo từ bài 1, xây dựng thêm hàm tìm kiếm trong danh sách liên kết đôi
Yêu cầu người dùng nhập vào số nguyên dương bất kỳ
kiểm tra xem số được nhập có trùng với dữ liệu phần tử nào trong danh sách liên kết không và in kết quả
Input

Output

1<->2<->3<->4<->5->NULL

3

True

1<->2<->3<->4<->5->NULL

7

False*/
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
int searchInList(Node* head, int value) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == value) {
            return 1; // Found
        }
        current = current->next;
    }
    return 0; // Not found
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

    int valueToSearch;
    printf("Nhap so nguyen duong can tim: ");
    scanf("%d", &valueToSearch);

    if (searchInList(head, valueToSearch)) {
        printf("True\n");
    } else {
        printf("False\n");
    }

    Node* current = head;
    Node* temp;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}