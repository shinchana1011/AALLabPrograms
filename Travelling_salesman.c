#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#define V 4
int min(int a, int b) {
    return (a < b) ? a : b;
}
int tsp(int graph[V][V], bool visited[V], int currentPos, int count, int cost, int min_cost) {
    if (count == V && graph[currentPos][0]) {
        return min(min_cost, cost + graph[currentPos][0]);
    }
    for (int i = 0; i < V; i++) {
        if (!visited[i] && graph[currentPos][i]) {
            visited[i] = true;
            min_cost = tsp(graph, visited, i, count + 1, cost + graph[currentPos][i], min_cost);
            visited[i] = false; // Backtrack
        }
    }
    return min_cost;
}
int main() {
    int graph[V][V] = {
        {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
    };
    bool visited[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }
    visited[0] = true;
    int min_cost = INT_MAX;
    min_cost = tsp(graph, visited, 0, 1, 0, min_cost);

    printf("Minimum cost for TSP: %d\n", min_cost);
    return 0;
}

