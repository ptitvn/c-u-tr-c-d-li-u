#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct {
    char data[MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, char value) {
    if (s->top < MAX - 1) {
        s->data[++s->top] = value;
    }
}

char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[s->top--];
    }
    return '\0';
}

char peek(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[s->top];
    }
    return '\0';
}

int isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

int isValidBrackets(char expr[]) {
    Stack s;
    initStack(&s);
    int len = strlen(expr);
    for (int i = 0; i < len; i++) {
        char c = expr[i];
        if (c == '(' || c == '[' || c == '{') {
            push(&s, c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (isEmpty(&s) || !isMatching(pop(&s), c)) {
                return 0; // false
            }
        }
    }
    return isEmpty(&s); // true nếu stack rỗng
}

int main() {
    char expr[MAX];
    printf("Nhap bieu thuc: ");
    fgets(expr, MAX, stdin);
    int len = strlen(expr);
    if (len > 0 && expr[len - 1] == '\n') expr[len - 1] = '\0';

    if (isValidBrackets(expr)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    return 0;
}