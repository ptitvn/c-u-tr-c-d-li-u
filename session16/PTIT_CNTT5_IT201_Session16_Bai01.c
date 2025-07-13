#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q == NULL) {
        printf("Không thể cấp phát bộ nhớ!\n");
        exit(1);
    }
    q->front = NULL;
    q->rear = NULL;
    return q;
}

bool isEmpty(Queue* q) {
    return q->front == NULL;
}

void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Không thể cấp phát bộ nhớ cho node mới!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Hang doi rong .\n");
        return -1;
    }
    Node* temp = q->front;
    int value = temp->data;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return value;
}

// Hàm xem phần tử đầu hàng đợi
int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("hàng doi rong!\n");
        return -1;
    }
    return q->front->data;
}

// Hàm giải phóng hàng đợi
void freeQueue(Queue* q) {
    while (!isEmpty(q)) {
        dequeue(q);
    }
    free(q);
}

// Hàm main kiểm thử hàng đợi
int main() {
    Queue* myQueue = createQueue();

    enqueue(myQueue, 10);
    enqueue(myQueue, 20);
    enqueue(myQueue, 30);

    printf("Phan tu dau : %d\n", peek(myQueue));

    printf("Loai bo: %d\n", dequeue(myQueue));
    printf("Loai bo: %d\n", dequeue(myQueue));

    printf("Phan tu dau: %d\n", peek(myQueue));

    freeQueue(myQueue);

    return 0;
}