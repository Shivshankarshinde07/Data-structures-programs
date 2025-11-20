#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;
int n;

void push(int x) {
    stack[++top] = x;
}

// DFS for Topological Sort
void dfs(int u) {
    visited[u] = 1;

    for (int v = 0; v < n; v++) {
        if (adj[u][v] == 1 && visited[v] == 0) {
            dfs(v);
        }
    }
    push(u);  
}

// Topological Sort using DFS
void topologicalSort() {
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    top = -1;

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0)
            dfs(i);
    }

    printf("Topological Order: ");
    while (top >= 0)
        printf("%d ", stack[top--]);
    printf("\n");
}

int main() {
    int edges, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter %d directed edges (u v) means u -> v:\n", edges);
    for (int i = 0; i < edges; i++) {
        scanf("%d%d", &u, &v);
        adj[u][v] = 1;  
    }

    topologicalSort();

    return 0;
}
