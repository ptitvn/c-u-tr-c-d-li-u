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
void deleteAtPosition(Node** head_ref, int position) {
    if (*head_ref == NULL || position <= 0) {
        return; 
    }
    
    Node* temp = *head_ref;
    
    if (position == 1) {
        *head_ref = temp->next; 
        free(temp); 
        return;
    }
    
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL || temp->next == NULL) {
        return;
    }
    
    Node* next = temp->next->next; 
    free(temp->next); 
    temp->next = next; 
}
int main() {
    Node* head = NULL;

    for (int i = 1; i <= 5; i++) {
        Node* newNode = createNode(i);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    printf("Danh sach lien ket ban dau: ");
    printList(head);

    int position;
    printf("Nhap vi tri muon xoa: ");
    scanf("%d", &position);

    deleteAtPosition(&head, position);

    printf("Danh sach lien ket sau khi xoa: ");
    printList(head);

    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}