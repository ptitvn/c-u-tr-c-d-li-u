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
int findMax(Node* root) {
    if (root == NULL) {
        return -1; 
    }
    int max = root->data;
    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);
    
    if (leftMax > max) {
        max = leftMax;
    }
    if (rightMax > max) {
        max = rightMax;
    }
    
    return max;
}
int main() {
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);

    int maxValue = findMax(root);
    printf("max value: %d\n", maxValue);

    free(root->left->left);
    free(root->left->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}