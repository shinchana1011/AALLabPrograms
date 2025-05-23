6. Execute a C program to demonstrate the working of Prim's Algorithm for finding the Minimum
Spanning Tree (MST) of a connected, undirected, weighted graph.

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 5  // Number of vertices in the graph

// Function to find the vertex with the minimum key value
int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index = -1;
    int v;
    for (v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to print the original adjacency matrix
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

// Function to print the MST
void printMST(int parent[], int graph[V][V]) {
    printf("Minimum Spanning Tree (Prim's Algorithm):\n");
    printf("Edge \tWeight\n");
    int i;
for (i = 1; i < V; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}

// Prim’s algorithm implementation
void primMST(int graph[V][V]) {
    int parent[V];  // Stores MST structure
    int key[V];     // Used to pick minimum weight edge
    bool mstSet[V]; // Tracks vertices included in MST
int i, count, v;
    for (i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1; // Start vertex has no parent

    for (count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for (v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printGraphMatrix(graph); // ?? Print original matrix before MST
    printMST(parent, graph); // ?? Print MST
}

int main() {
    int graph[V][V] = {
        {0, 10, 0, 5, 3},
        {10, 0, 1, 0, 0},
        {0, 1, 0, 0, 4},
        {5, 0, 0, 0, 8},
        {3, 0, 4, 8, 0}
    };

    primMST(graph);
    return 0;
}
