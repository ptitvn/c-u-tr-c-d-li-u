#include <stdio.h>
#include <stdlib.h>

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
        printf("Khong the cap phat bo nho\n");
        exit(1);
    }
    q->front = NULL;
    q->rear = NULL;
    return q;
}

Node* createNode() {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Khong the cap phat bo nho cho node\n");
        exit(1);
    }
    printf("Nhap so nguyen: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    return newNode;
}

void enqueueNode(Queue* q) {
    Node* newNode = createNode();
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int getFrontValue(Queue* q) {
    if (q->front == NULL) {
        printf("empty queue\n");
        return -1; 
    } else {
        return q->front->data;
    }
}

void displayQueue(Queue* q) {
    if (q->front == NULL) {
        printf("queue is empty\n");
        return;
    }
    Node* temp = q->front;
    printf("Hang doi: ");
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Queue* queue = createQueue();

    displayQueue(queue); 
    int val1 = getFrontValue(queue); 
    if (val1 != -1) printf("%d\n", val1);

    enqueueNode(queue); // nhập 1
    enqueueNode(queue); // nhập 2
    enqueueNode(queue); // nhập 5

    displayQueue(queue); 
    int val2 = getFrontValue(queue); 
    if (val2 != -1)
        printf("%d\n", val2);

    return 0;
}