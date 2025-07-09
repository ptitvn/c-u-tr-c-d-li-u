#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Khong du bo nho\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void initStack(Stack* s) {
    s->top = NULL;
}

void push(Stack* s, int value) {
    Node* newNode = createNode(value);
    newNode->next = s->top;
    s->top = newNode;
}

void printStackLIFO(Stack* s) {
    if (s->top == NULL) {
        printf("Ngan xep trong\n");
        return;
    }
    Node* curr = s->top;
    while (curr != NULL) {
        printf("%d\n", curr->data);
        curr = curr->next;
    }
}

void displayStackState(Stack* s) {
    Node* curr = s->top;
    printf("stack={\n  ");
    if (curr == NULL) {
        printf("NULL\n");
    } else {
        while (curr != NULL) {
            printf("%d", curr->data);
            curr = curr->next;
            if (curr != NULL) printf("->");
        }
        printf("->NULL\n");
    }
    printf("}\n");
}

int main() {
    Stack s;
    initStack(&s);
    for (int i = 5; i >= 1; i--) {
        push(&s, i);
    }
    displayStackState(&s);

    int x;
    scanf("%d", &x);
    push(&s, x);

    printStackLIFO(&s);

    Stack s2;
    initStack(&s2);
    displayStackState(&s2);
    scanf("%d", &x);
    push(&s2, x);
    printStackLIFO(&s2);

    Stack s3;
    initStack(&s3);
    printStackLIFO(&s3);

    return 0;
}