#include <stdio.h>

#define MAX_SIZE 5

typedef struct {
    int array[MAX_SIZE];
    int top;
} Stack;

// Hàm khởi tạo ngăn xếp
void initStack(Stack *stack) {
    stack->top = -1;
}

// Hàm kiểm tra ngăn xếp có rỗng hay không
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Hàm kiểm tra ngăn xếp có đầy hay không
int isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Hàm thêm phần tử vào ngăn xếp
void push(Stack *stack, int item) {
    if (isFull(stack)) {
        printf("Ngan xep da day %d.\n", item);
        return;
    }
    stack->array[++stack->top] = item;
    printf("da them phan tu %d vao.\n", item);
}

int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Ngan xep rong.\n");
        return -1;
    }
    return stack->array[stack->top--];
}

int main() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Phan tu tren cung: %d\n", pop(&stack));

    return 0;
}