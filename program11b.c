#include <stdio.h>

int n, graph[50][50];
int visited[50];

void dfs(int v) {
    int i;
    visited[v] = 1;

    for (i = 0; i < n; i++) {
        if (graph[v][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    for (i = 0; i < n; i++)
        visited[i] = 0;

    dfs(0);  // Start DFS from vertex 0

    for (i = 0; i < n; i++) {
        if (!visited[i]) {
            printf("Graph is NOT connected\n");
            return 0;
        }
    }

    printf("Graph is connected\n");
    return 0;
}
