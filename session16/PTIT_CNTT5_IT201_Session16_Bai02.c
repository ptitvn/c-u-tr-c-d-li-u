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
    if (!q) {
        printf("Khong the cap phat bo nho\n");
        exit(1);
    }
    q->front = NULL;
    q->rear = NULL;
    return q;
}
Node* createNode() {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Khong the cap phat bo nho cho node moi!\n");
        exit(1);
    }
    printf("Nhap so nguyen : ");
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
    printf("Da them hang doi: %d\n", newNode->data);
}
int main() {
    Queue* myQueue = createQueue();

    enqueueNode(myQueue);
    enqueueNode(myQueue); 
    enqueueNode(myQueue); 

    printf("trang thai hang doi: ");
    Node* temp = myQueue->front;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    return 0;
}