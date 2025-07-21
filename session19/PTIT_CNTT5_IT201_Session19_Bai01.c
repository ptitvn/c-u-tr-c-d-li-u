#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Khong du bo nho\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
int main() {
    int value;
    printf("Nhap gia tri cho node: ");
    scanf("%d", &value);
    
    Node* node = createNode(value);
    
    printf("node = {\n");
    printf("   data: %d,\n", node->data);
    printf("   left->NULL,\n");
    printf("   right->NULL\n");
    printf("}\n");
    
    free(node); 
    return 0;
}
