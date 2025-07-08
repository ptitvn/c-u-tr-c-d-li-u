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

int isPalindrome(char str[]) {
    Stack s;
    initStack(&s);
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        push(&s, str[i]);
    }

    // So sánh từng ký tự với ký tự lấy ra từ stack
    for (int i = 0; i < len; i++) {
        if (str[i] != pop(&s)) {
            return 0; 
        }
    }
    return 1; 
}

int main() {
    char str[MAX];
    printf("Nhap chuoi: ");
    fgets(str, MAX, stdin);
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') str[len - 1] = '\0';

    if (isPalindrome(str)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    return 0;
}