#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Khong du bo nho!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

typedef struct Stack {
    Node* top;
} Stack;

Stack* createStack() {
    Stack* newStack = (Stack*)malloc(sizeof(Stack));
    if (newStack == NULL) {
        printf("Khong du bo nho!\n");
        exit(1);
    }
    newStack->top = NULL;
    return newStack;
}

int main() {
    Stack* myStack = createStack();

    if (myStack != NULL) {
        printf("khoi tao thanh cong.\n");
        if (myStack->top == NULL) {
            printf("Node dau tien la null.\n");
        } else {
            printf("Node dau tien khac null .\n");
        }
    } else {
        printf("Khong the khoi tao ngan xep .\n");
    }

    free(myStack);
    myStack = NULL;

    return 0;
}