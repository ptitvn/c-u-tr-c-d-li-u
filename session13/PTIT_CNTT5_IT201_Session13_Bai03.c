#include <stdio.h>
#define MAX 5

typedef struct {
    int data[MAX];
    int top;
    int cap;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
    s->cap = MAX;
}

int push(Stack *s, int value) {
    if (s->top >= s->cap - 1) {
        printf("Stack day, khong the them!\n");
        return 0;
    }
    s->top++;
    s->data[s->top] = value;
    return 1;
}

int pop(Stack *s) {
    if (s->top == -1) {
        printf("No element in stack\n");
        return -1;
    }
    int value = s->data[s->top];
    s->top--;
    return value;
}

void printStack(Stack *s) {
    printf("stack={\n    elements: [");
    for (int i = 0; i <= s->top; i++) {
        printf("%d", s->data[i]);
        if (i < s->top) printf(", ");
    }
    printf("],\n    top: %d,\n    cap: %d\n}\n", s->top, s->cap);
}

int main() {
    Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);
    push(&s, 50);

    printStack(&s);

    int value = pop(&s);
    if (value != -1) {
        printf("%d\n", value);
    }

    printStack(&s);

    while (pop(&s) != -1);
    printStack(&s);

    pop(&s);

    return 0;
}