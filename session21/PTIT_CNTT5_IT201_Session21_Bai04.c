#include <stdio.h>

void addEdge(int graph[3][3], int u, int v) {
    graph[u][v] = 1;
}

void printMatrix(int graph[3][3]) {
    for (int i = 0; i < 3; i++) {
        printf(" ");
        for (int j = 0; j < 3; j++) {
            printf("%d", graph[i][j]);
            if (j < 2) printf(", ");
        }
        printf("\n");
    }
}

int main() {
    int graph[3][3] = { {0,0,0}, {0,0,0}, {0,0,0} };
    printf("Ma tran ban dau:\n");
    printMatrix(graph);
    
    addEdge(graph, 1, 0);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    printf("Ma tran sau khi them canh:\n");
    printMatrix(graph);

    return 0;
}