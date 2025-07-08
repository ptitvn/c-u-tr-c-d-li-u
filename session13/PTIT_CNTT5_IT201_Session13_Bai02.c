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

int main() {
    Stack s;
    initStack(&s);

    printf("Nhap cac phan tu:\n");
    for (int i = 0; i < MAX; i++) {
        int x;
        
        scanf("%d", &x);
        push(&s, x);
    }

    printStack(&s);

    return 0;
}