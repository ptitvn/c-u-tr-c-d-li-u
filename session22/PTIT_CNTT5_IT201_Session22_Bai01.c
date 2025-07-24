#include <stdio.h>

void addEdge(int graph[5][5], int u, int v) {
    graph[u][v] = 1; 
    graph[v][u] = 1; 
}
void printGraph(int graph[5][5], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int n = 5; 
    int graph[5][5] = {0};

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 3, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 3, 4);

    printGraph(graph, n);

    return 0;
}