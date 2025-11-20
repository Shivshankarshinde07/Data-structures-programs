#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int n;  // number of vertices

// Queue for BFS
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x) {
    if (rear == MAX-1) return;
    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1) return -1;
    int x = queue[front++];
    if (front > rear) front = rear = -1;
    return x;
}

// BFS - Breadth First Search
void BFS(int start) {
    for (int i = 0; i < n; i++) visited[i] = 0;

    printf("BFS Traversal: ");
    enqueue(start);
    visited[start] = 1;

    while (front <= rear) {
        int curr = dequeue();
        printf("%d ", curr);

        for (int i = 0; i < n; i++) {
            if (adj[curr][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

// DFS - Depth First Search (Recursive)
void DFS_Util(int vertex) {
    printf("%d ", vertex);
    visited[vertex] = 1;

    for (int i = 0; i < n; i++) {
        if (adj[vertex][i] == 1 && !visited[i]) {
            DFS_Util(i);
        }
    }
}

void DFS(int start) {
    for (int i = 0; i < n; i++) visited[i] = 0;
    printf("DFS Traversal: ");
    DFS_Util(start);
    printf("\n");
}

int main() {
    int edges, u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize adjacency matrix to 0
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter %d edges (u v):\n", edges);
    for (int i = 0; i < edges; i++) {
        scanf("%d%d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;  // Undirected graph
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    BFS(start);
    DFS(start);

    return 0;
}
