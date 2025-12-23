#include <stdio.h>

int queue[50], front = -1, rear = -1;
int visited[50];
int n, graph[50][50];

void enqueue(int v) {
    if (rear == 49) return;
    if (front == -1) front = 0;
    queue[++rear] = v;
}

int dequeue() {
    return queue[front++];
}

void bfs(int start) {
    int i, v;
    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (front <= rear) {
        v = dequeue();
        printf("%d ", v);

        for (i = 0; i < n; i++) {
            if (graph[v][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}

int main() {
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    bfs(start);
    return 0;
}
