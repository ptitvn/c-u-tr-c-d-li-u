#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Loi: Khong du bo nho de tao Node moi.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Stack* createStack() {
    Stack* newStack = (Stack*)malloc(sizeof(Stack));
    if (newStack == NULL) {
        printf("Loi: Khong du bo nho de tao Ngan xep moi.\n");
        exit(1);
    }
    newStack->top = NULL;
    return newStack;
}

void push(Stack* stack, int data) {
    Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

void displayStackState(Stack* stack) {
    Node* current = stack->top;
    printf("stack={\n");
    if (current == NULL) {
        printf("   NULL\n");
    } else {
        printf("  ");
        while (current != NULL) {
            printf("%d", current->data);
            current = current->next;
            if (current != NULL) {
                printf("->");
            }
        }
        printf("->NULL\n");
    }
    printf("}\n");
}

int main() {
    Stack* myStack = createStack();
    push(myStack, 5);
    push(myStack, 4);
    push(myStack, 3);
    push(myStack, 2);
    push(myStack, 1);

    printf("Input:\n");
    displayStackState(myStack);

    int valueToPush;
    printf("Nhap so nguyen duong bat ky de them vao ngan xep: ");
    scanf("%d", &valueToPush);
    push(myStack, valueToPush);

    printf("Output:\n");
    displayStackState(myStack);

    Stack* emptyStack = createStack();
    printf("stack={\n   NULL\n}\n");
    printf("Nhap so nguyen duong bat ky de them vao ngan xep: ");
    scanf("%d", &valueToPush);
    push(emptyStack, valueToPush);
    printf("stack={\n  ");
    displayStackState(emptyStack);

    Node* current = myStack->top;
    while(current != NULL) {
        Node* nextNode = current->next;
        free(current);
        current = nextNode;
    }
    free(myStack);

    current = emptyStack->top;
    while(current != NULL) {
        Node* nextNode = current->next;
        free(current);
        current = nextNode;
    }
    free(emptyStack);

    return 0;
}