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

void printStack(Stack *s) {
    printf("stack={\n    elements: [");
    for (int i = 0; i <= s->top; i++) {
        printf("%d", s->data[i]);
        if (i < s->top) printf(", ");
    }
    printf("],\n    top: %d,\n    cap: %d\n}\n", s->top, s->cap);
}

void printStackLIFO(Stack *s) {
    for (int i = s->top; i >= 0; i--) {
        printf("%d\n", s->data[i]);
    }
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

    printStackLIFO(&s);

    return 0;
}