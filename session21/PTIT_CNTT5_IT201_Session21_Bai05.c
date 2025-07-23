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
void addEdge(Node* graph[], int u, int v) {
    Node* nodeV = createNode(v);
    nodeV->next = graph[u];
    graph[u] = nodeV;

    Node* nodeU = createNode(u);
    nodeU->next = graph[v];
    graph[v] = nodeU;
}
void printGraph(Node* graph[], int n) {
    printf("[\n");
    for (int i = 0; i < n; i++) {
        printf(" ");
        Node* curr = graph[i];
        if (!curr) {
            printf("NULL");
        } else {
            while (curr) {
                printf("%d", curr->data);
                if (curr->next) printf("->");
                curr = curr->next;
            }
            printf("->NULL");
        }
        printf("\n");
    }
    printf("]\n");
}
int main() {
    int n = 3;
    Node* graph[3] = {NULL, NULL, NULL};

    printGraph(graph, n);

    addEdge(graph, 1, 2);
    printGraph(graph, n);

    addEdge(graph, 0, 1);
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