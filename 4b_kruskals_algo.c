#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define V 5

struct Edge {
    int src, dest, weight;
};

// For union-find
int parent[V];

int find(int i) {
    if (parent[i] != i)
        parent[i] = find(parent[i]);
    return parent[i];
}

void unionSets(int x, int y) {
    int xroot = find(x);
    int yroot = find(y);
    parent[xroot] = yroot;
}

int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

void printGraphMatrix(int graph[V][V]) {
    printf("Original Graph (Adjacency Matrix):\n");
    int i, j;
for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            printf("%2d ", graph[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void kruskalMST(struct Edge edges[], int edgeCount) {
    struct Edge result[V]; // To store MST edges
    int e = 0, i = 0, v;

    // Sort edges by weight
    qsort(edges, edgeCount, sizeof(struct Edge), compareEdges);

    for (v = 0; v < V; v++)
        parent[v] = v;

    while (e < V - 1 && i < edgeCount) {
        struct Edge next = edges[i++];

        int x = find(next.src);
        int y = find(next.dest);

        if (x != y) {
            result[e++] = next;
            unionSets(x, y);
        }
    }

    printf("Minimum Spanning Tree (Kruskal's Algorithm):\n");
    printf("Edge \tWeight\n");
    for (i = 0; i < e; i++) {
        printf("%d - %d \t%d\n", result[i].src, result[i].dest, result[i].weight);
    }
}

int main() {
    int graph[V][V] = {
        {0, 10, 0, 5, 3},
        {10, 0, 1, 0, 0},
        {0, 1, 0, 0, 4},
        {5, 0, 0, 0, 8},
        {3, 0, 4, 8, 0}
    };

    // Step 1: Print matrix
    printGraphMatrix(graph);

    // Step 2: Convert matrix to edge list
    struct Edge edges[V * V];
    int edgeCount = 0;
    int i, j;

    for (i = 0; i < V; i++) {
        for (j = i + 1; j < V; j++) {
            if (graph[i][j] != 0) {
                edges[edgeCount].src = i;
                edges[edgeCount].dest = j;
                edges[edgeCount].weight = graph[i][j];
                edgeCount++;
            }
        }
    }

    // Step 3: Run Kruskal's algorithm
    kruskalMST(edges, edgeCount);

    return 0;
}
