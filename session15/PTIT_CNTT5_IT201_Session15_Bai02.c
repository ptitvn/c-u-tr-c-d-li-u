#include <stdio.h>

#define MAX 100  

typedef struct {
    int array[MAX];
    int front;
    int rear;
    int capacity;
} Queue;

// Khởi tạo hàng đợi
void initQueue(Queue *q, int cap) {
    q->front = 0;
    q->rear = -1;
    q->capacity = cap;
}

void enqueueInput(Queue *q) {
    if (q->rear + 1 >= q->capacity) {
        printf("queue is full\n\n");
        return;
    }

    int value;
    scanf("%d", &value); 

    q->rear++;
    q->array[q->rear] = value;

    printf("queue = {\n");
    printf("   array = [");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d", q->array[i]);
        if (i < q->rear) printf(", ");
    }
    printf("],\n   front = %d,\n   rear = %d,\n   capacity = %d\n}\n\n", q->front, q->rear, q->capacity);
}

int main() {
    Queue q;
    initQueue(&q, 5); 

    for (int i = 0; i < 5; i++) {
        enqueueInput(&q);
    }

    enqueueInput(&q);

    return 0;
}