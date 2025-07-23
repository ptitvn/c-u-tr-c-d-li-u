#include <stdio.h>
#include <stdlib.h>

void addEdge(int graph[4][4], int u, int v) {
    graph[u][v] = 1; 
    graph[v][u] = 1; 
}
int main() {
    int graph[4][4] = { 
        {0, 0, 0, 0},
        {0, 0, 0, 0}, 
        {0, 0, 0, 0}, 
        {0, 0, 0, 0} 
    }; 

    printf("Ma tran ban dau:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    addEdge(graph, 0, 1); 
    addEdge(graph, 0, 2); 
    addEdge(graph, 1, 2); 
    addEdge(graph, 2, 3); 

    printf("Ma tran sau khi them canh:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}
