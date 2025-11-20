#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int disc[MAX];
int low[MAX];
int parent[MAX];
int time = 0;
int n;

void addEdge(int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;
}

int isBiconnectedUtil(int u) {
    visited[u] = 1;
    disc[u] = low[u] = time++;
    int children = 0;

    for (int v = 0; v < n; v++) {
        if (adj[u][v] == 0) continue;

        if (visited[v] == 0) {
            children++;
            parent[v] = u;

            if (isBiconnectedUtil(v) == 0) return 0;

            low[u] = (low[u] < low[v]) ? low[u] : low[v];

            if (parent[u] == -1 && children > 1) return 0;
            if (parent[u] != -1 && low[v] >= disc[u]) return 0;
        }
        else if (v != parent[u]) {
            low[u] = (low[u] < disc[v]) ? low[u] : disc[v];
        }
    }
    return 1;
}

int isBiconnected() {
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        disc[i] = low[i] = -1;
        parent[i] = -1;
    }
    time = 0;

    if (isBiconnectedUtil(0) == 0) return 0;

    for (int i = 0; i < n; i++)
        if (visited[i] == 0) return 0;

    return 1;
}

// Check if Graph is Biconnected
int main() {
    int edges, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        scanf("%d%d", &u, &v);
        addEdge(u, v);
    }

    if (isBiconnected())
        printf("\nGraph is BICONNECTED\n");
    else
        printf("\nGraph is NOT BICONNECTED\n");

    return 0;
}
