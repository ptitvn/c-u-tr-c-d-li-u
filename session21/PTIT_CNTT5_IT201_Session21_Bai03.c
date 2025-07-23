#include <stdio.h>

void addEdge(int graph[3][3], int u, int v) {
    graph[u - 1][v - 1] = 1;
}

void printMatrix(int graph[3][3]) {
    printf("[\n");
    for (int i = 0; i < 3; i++) {
        printf(" ");
        for (int j = 0; j < 3; j++) {
            printf("%d", graph[i][j]);
            if (j < 2) printf(", ");
        }
        printf("\n");
    }
    printf("]\n");
}

int main() {
    int graph[3][3] = { {0,0,0}, {0,0,0}, {0,0,0} };

    printMatrix(graph);

    int startNode = 2;
    int endNode = 3;

    addEdge(graph, startNode, endNode);

    printMatrix(graph);

    return 0;
}