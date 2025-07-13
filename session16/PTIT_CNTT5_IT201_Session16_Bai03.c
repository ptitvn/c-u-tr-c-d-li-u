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
void peekFront(Queue* q) {
    if (q->front == NULL) {
        printf("queue is empty\n");
    } else {
        printf("%d\n", q->front->data);
    }
}
void displayQueue(Queue* q) {
    if (q->front == NULL) {
        printf("queue is empty\n");
        return;
    }
    Node* temp = q->front;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    Queue* queue = createQueue();

    displayQueue(queue); 
    peekFront(queue);  
    
    enqueueNode(queue);  
    enqueueNode(queue); 
    enqueueNode(queue);  

    displayQueue(queue);
    peekFront(queue);    

    return 0;
}