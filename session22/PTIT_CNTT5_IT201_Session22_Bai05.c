#include <stdio.h>
#include <stdlib.h>
/*Viết chương trình nhập vào n đỉnh v với 0 < n, v < 100
Thực hiện nhập vào các cạnh của đồ thị vô hướng 
Thực hiện nhập vào đỉnh k cần đếm số đỉnh liền kề
 

INPUT

OUTPUT

Nhap so dinh va so canh: 5 6

Nhap cac canh:

0 1

0 2

1 2

3 2

1 3

3 4

Nhap dinh k muon kiem tra: 3

So dinh ke voi 3 la: 3

*/
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
int countAdjacentVertices(Node* graph[], int n, int k) {
    int count = 0;
    Node* curr = graph[k];
    while (curr) {
        count++;
        curr = curr->next;
    }
    return count;
}
int main() {
    int n, m, k;
    printf("Nhap so dinh va so canh: ");
    scanf("%d %d", &n, &m);
    
    Node* graph[n];
    for (int i = 0; i < n; i++) {
        graph[i] = NULL;
    }

    printf("Nhap cac canh:\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    printf("Nhap dinh k muon kiem tra: ");
    scanf("%d", &k);

    printGraph(graph, n);
    
    int adjacentCount = countAdjacentVertices(graph, n, k);
    printf("So dinh ke voi %d la: %d\n", k, adjacentCount);

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