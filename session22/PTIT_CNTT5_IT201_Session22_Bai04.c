#include <stdio.h>

int countEdges(int n, int graph[n][n]) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) { 
            if (graph[i][j] == 1) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    int n = 5; 
    int graph[5][5] = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {0, 0, 0, 1, 0}
    };

    printf("So canh trong do thi: %d\n", countEdges(n, graph));
    return 0;
}
