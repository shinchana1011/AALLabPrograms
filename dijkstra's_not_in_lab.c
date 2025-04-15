#include <stdio.h>
#define INF 9999
#define V 5

void dijkstra(int graph[V][V], int start) {
    int dist[V], visited[V] = {0}, totalCost = 0;

    for (int i = 0; i < V; i++)
        dist[i] = INF;
    dist[start] = 0;

    for (int i = 0; i < V - 1; i++) {
        int min = INF, u;
        for (int j = 0; j < V; j++)
            if (!visited[j] && dist[j] < min)
                min = dist[j], u = j;

        visited[u] = 1;

        for (int v = 0; v < V; v++)
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printf("Shortest distances from node %d:\n", start);
    for (int i = 0; i < V; i++) {
        printf("To %d = %d\n", i, dist[i]);
        if (dist[i] != INF)
            totalCost += dist[i];
    }

    printf("Total cost: %d\n", totalCost);
}

int main() {
    int graph[V][V] = {
        {0, 6, 0, 1, 0},
        {6, 0, 5, 2, 2},
        {0, 5, 0, 0, 5},
        {1, 2, 0, 0, 1},
        {0, 2, 5, 1, 0}
    };

    dijkstra(graph, 0);
    return 0;
}
