#include <stdio.h>
#define MAX 100

typedef struct {
    int array[MAX];
    int front;
    int rear;
    int capacity;
} Queue;

void initQueue(Queue *q, int capacity) {
    q->front = 0;
    q->rear = -1;
    q->capacity = capacity;
}

void enqueue(Queue *q) {
    if (q->rear + 1 >= q->capacity) {
        printf("Queue is full\n\n");
        return;
    }

    int value;
    printf("Nhap so nguyen de them vao hang doi: ");
    scanf("%d", &value);

    q->rear++;
    q->array[q->rear] = value;

    printf("Queue = {\n");
    printf("  array = [");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d", q->array[i]);
        if (i < q->rear) printf(", ");
    }
    printf("],\n  front = %d,\n  rear = %d,\n  capacity = %d\n}\n\n",
           q->front, q->rear, q->capacity);
}

int main() {
    Queue queue;
    int cap;
    printf("Nhap suc chua toi da cua hang doi: ");
    scanf("%d", &cap);

    initQueue(&queue, cap);

    printf("\nQueue = {\n  array = [],\n  front = 0,\n  rear = -1,\n  capacity = %d\n}\n\n", queue.capacity);

    for (int i = 0; i < 5; i++) {
        enqueue(&queue);
    }

    return 0;
}