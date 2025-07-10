#include <stdio.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int front;
    int rear;
} Queue;

// Khởi tạo hàng đợi
void initQueue(Queue *q) {
    q->front = 0;
    q->rear = -1;
}

int isFull(Queue *q) {
    return q->rear == MAX - 1;
}

// Thêm phần tử vào hàng đợi
int enqueue(Queue *q, int value) {
    if (isFull(q)) {
        printf("Hang doi da day khong the them vao phan tu %d.\n", value);
        return 0;
    }
    q->rear++;
    q->data[q->rear] = value;
    return 1;
}

int main() {
    Queue myQueue;

    initQueue(&myQueue);
    printf("Queue initialized.\n");
    printf("Front index: %d\n", myQueue.front);
    printf("Rear index: %d\n", myQueue.rear);

    // Thêm phần tử vào hàng đợi
    int elementToAdd = 10;
    if (enqueue(&myQueue, elementToAdd)) {
        printf("Da them phan tu %d vao hang doi.\n", elementToAdd);
    }

    // In lại chỉ số sau khi thêm
    printf("Front index: %d\n", myQueue.front);
    printf("Rear index: %d\n", myQueue.rear);

    return 0;
}