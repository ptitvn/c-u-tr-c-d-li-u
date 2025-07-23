#include <stdio.h>

void addEdge(int graph[3][3], int u, int v) {
    graph[u - 1][v - 1] = 1; 
    graph[v - 1][u - 1] = 1; 
}
int main() {
    int graph[3][3] = { 
        {0, 0, 0},
         {0, 0, 0}, 
         {0, 0, 0} 
}; 

    printf("Ma tran ban dau:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    int firstNode = 1;
    int secondNode = 2;

    addEdge(graph, firstNode, secondNode); 

    printf("Ma tran sau khi them canh giua node %d va node %d:\n", firstNode, secondNode);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}