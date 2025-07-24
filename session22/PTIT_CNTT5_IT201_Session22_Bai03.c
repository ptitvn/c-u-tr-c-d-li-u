#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void appendNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* curr = *head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

void matrixToList(int matrix[][100], Node* graph[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1) {
                appendNode(&graph[i], j);
            }
        }
    }
}

void printGraph(Node* graph[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d: ", i);
        Node* curr = graph[i];
        if (!curr) {
            printf("NULL");
        } else {
            while (curr) {
                printf("%d", curr->data);
                if (curr->next) printf(" -> ");
                curr = curr->next;
            }
            printf(" -> NULL");
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Nhap so dinh cua do thi: ");
    scanf("%d", &n);
    int matrix[100][100];
    Node* graph[100];
    for (int i = 0; i < n; i++) {
        graph[i] = NULL;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
        printf("Nhap gia tri ma tran [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    matrixToList(matrix, graph, n);

    printGraph(graph, n);

    for (int i = 0; i < n; i++) {
        Node* curr = graph[i];
        while (curr) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    return 0;
}