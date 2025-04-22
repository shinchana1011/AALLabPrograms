#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;
int isAlpha = 0; // 0 for numbers, 1 for alphabets

void dfs(int v, int n) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i]) {
            dfs(i, n);
        }
    }
    stack[++top] = v;
}

void topologicalSort(int n) {
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i])
            dfs(i, n);
    }

    printf("Topological Sort: ");
    while (top != -1) {
        if (isAlpha)
            printf("%c ", stack[top--] + 'A'); // Alphabet output
        else
            printf("%d ", stack[top--]);       // Numeric output
    }
    printf("\n");
}

int main() {
    int n, e;
    char type;

    printf("Enter vertex label type (A for alphabets, N for numbers): ");
    scanf(" %c", &type);
    isAlpha = (type == 'A' || type == 'a') ? 1 : 0;

    printf("Enter number of vertices (max 100): ");
    scanf("%d", &n);

    // Initialize adjacency matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges:\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        if (isAlpha) {
            char a, b;
            scanf(" %c %c", &a, &b);
            u = toupper(a) - 'A';
            v = toupper(b) - 'A';
        } else {
            scanf("%d %d", &u, &v);
        }
        adj[u][v] = 1;
    }

    topologicalSort(n);

    return 0;
}
