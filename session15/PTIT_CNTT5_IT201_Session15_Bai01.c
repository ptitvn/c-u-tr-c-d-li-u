#include <stdio.h>

#define MAX 100 

typedef struct {
    int data[MAX]; 
    int front;   
    int rear;     
} Queue;
void initQueue(Queue *q) {
    q->front = 0;   
    q->rear = -1;   
}
int main() {
    Queue myQueue;
    initQueue(&myQueue);

    printf("Queue initialized.\n");
    printf("Front index: %d\n", myQueue.front);
    printf("Rear index: %d\n", myQueue.rear);

    return 0;
}