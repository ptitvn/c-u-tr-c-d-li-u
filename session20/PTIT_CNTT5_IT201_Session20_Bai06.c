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
int findLevel(Node* root, int value) {
    if (root == NULL)
        return -1; 
    if (root->data == value)
        return 0; 
    int leftLevel = findLevel(root->left, value);
    if (leftLevel != -1)
        return leftLevel + 1; 
    int rightLevel = findLevel(root->right, value); 
    if (rightLevel != -1)
        return rightLevel + 1; 
    return -1; 
}
int main() {
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    int valueToFind = 3;
    int level = findLevel(root, valueToFind);
    
    if (level != -1) {
        printf("value: %d\n", valueToFind);
        printf("Node level: %d\n", level);
    } else {
        printf("Value %d not found in the tree.\n", valueToFind);
    }

    free(root->left->left);
    free(root->left->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}