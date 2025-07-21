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
void addValue(Node* root, int value) {
    if (root == NULL) {
        return; 
    }
    
    Node* newNode = createNode(value);
    
    if (root->left == NULL) {
        root->left = newNode; 
    } else if (root->right == NULL) {
        root->right = newNode; 
    } else {
        addValue(root->left, value); 
    }
}
int main() {
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    int valueToAdd = 6;
    addValue(root, valueToAdd);

    printf("Cay sau khi them gia tri %d:\n", valueToAdd);
    printf("Root: %d\n", root->data);
    printf("Left Child: %d\n", root->left->data);
    printf("Right Child: %d\n", root->right->data);
    printf("Left Left Child: %d\n", root->left->left->data);
    printf("Left Right Child: %d\n", root->left->right ? root->left->right->data : -1);

    free(root->left->left);
    free(root->left->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
