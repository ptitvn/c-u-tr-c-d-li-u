#include <stdio.h>
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

int isFull(Stack *s, int n) {
    return s->top == n - 1;
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
    return -1;
}

void reverseArray(int arr[], int n) {
    Stack s;
    initStack(&s);
    // Đưa các phần tử vào stack
    for (int i = 0; i < n; i++) {
        push(&s, arr[i]);
    }
    // Lấy ra theo thứ tự LIFO để đảo ngược
    for (int i = 0; i < n; i++) {
        arr[i] = pop(&s);
    }
}

int main() {
    int n, arr[MAX];
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);
    if (n <= 0 || n > MAX) {
        printf("So phan tu khong hop le!\n");
        return 1;
    }
    printf("Nhap cac phan tu:\n");
    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ",i+1);
        scanf("%d", &arr[i]);
    }

    reverseArray(arr, n);

    printf("Mang sau khi dao nguoc:\n[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
    return 0;
}