#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void insert(Node** root, int data) {
    if (*root == NULL) {
        *root = createNode(data);
        return;
    }
    if (data < (*root)->data) {
        insert(&((*root)->left), data);
    } else {
        insert(&((*root)->right), data);
    }
}
Node* findMax(Node* root) {
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}
Node* deleteValue(Node* root, int value) {
    if (root == NULL) {
        return root;
    }
    if (value < root->data) {
        root->left = deleteValue(root->left, value);
    } else if (value > root->data) {
        root->right = deleteValue(root->right, value);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

    }
    Node* temp = findMax(root->left);
    root->data = temp->data;
    root->left = deleteValue(root->left, temp->data);
    return root;
    return root;
}
void printInOrder(Node* root) {
    if (root != NULL) {
        printInOrder(root->left);
        printf("%d ", root->data);
        printInOrder(root->right);
    }
}
int main() {
    Node* root = NULL;
    insert(&root, 5);
    insert(&root, 3);
    insert(&root, 7);
    insert(&root, 2);
    insert(&root, 4);
    insert(&root, 6);
    insert(&root, 8);

    printf("Tree before deletion: ");
    printInOrder(root);
    printf("\n");

    int valueToDelete = 3;
    root = deleteValue(root, valueToDelete);

    printf("Tree after deleting %d: ", valueToDelete);
    printInOrder(root);
    printf("\n");

    return 0;
}

