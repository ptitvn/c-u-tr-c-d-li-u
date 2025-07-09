#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

typedef struct {
    int data[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int value) {
    if (s->top < MAX - 1) {
        s->data[++s->top] = value;
    }
}

int pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[s->top--];
    }
    return 0;
}

int calcPostfix(char expr[]) {
    Stack s;
    initStack(&s);
    int len = strlen(expr);
    for (int i = 0; i < len; i++) {
        char c = expr[i];
        if (isdigit(c)) {
            push(&s, c - '0');
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            int b = pop(&s);
            int a = pop(&s);
            int res = 0;
            switch (c) {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/': res = a / b; break;
            }
            push(&s, res);
        }
    }
    return pop(&s);
}
int main() {
    char expr[MAX];
    printf("Nhap bieu thuc hau to: ");
    fgets(expr, MAX, stdin);
    int len = strlen(expr);
    if (len > 0 && expr[len - 1] == '\n') expr[len - 1] = '\0';

    int result = calcPostfix(expr);
    printf("%d\n", result);

    return 0;
}