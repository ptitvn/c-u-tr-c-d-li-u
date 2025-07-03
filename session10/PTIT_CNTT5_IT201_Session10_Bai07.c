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
int main(){
    Node* head = createNode(5);
    head->next = createNode(7);
    head->next->next = createNode(3);

    printf("Danh sach lien ket: ");
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("->NULL\n");

    // Sắp xếp danh sách liên kết theo thứ tự tăng dần
    Node* i, *j;
    int temp;
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }

    printf("Danh sach lien ket sau khi sap xep: ");
    current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("->NULL\n");

    // Giải phóng bộ nhớ
    current = head;
    Node* tempNode;
    while (current != NULL) {
        tempNode = current;
        current = current->next;
        free(tempNode);
    }

    return 0;
}
