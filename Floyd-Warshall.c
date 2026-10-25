#include <stdio.h>
#include <stdlib.h>

#define INF 99999

void floydWarshall(int **graph, int V);
void printSolution(int **dist, int V);

int main() {
    int V;
    printf("Enter the number of vertices: ");
    if (scanf("%d", &V) != 1 || V <= 0) {
        printf("Invalid number of vertices.\n");
        return 1;
    }
    int **graph = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        graph[i] = (int *)malloc(V * sizeof(int));
    }

    printf("\nEnter the adjacency matrix (%d x %d):\n", V, V);
    printf("(Use %d to represent Infinity/no direct edge)\n\n", INF);

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("Weight from vertex %d to %d: ", i, j);
            scanf("%d", &graph[i][j]);
        }
    }
    floydWarshall(graph, V);
    for (int i = 0; i < V; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}
void floydWarshall(int **graph, int V) {
    int **dist = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        dist[i] = (int *)malloc(V * sizeof(int));
    }
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && 
                    (dist[i][k] + dist[k][j] < dist[i][j])) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    printSolution(dist, V);
    for (int i = 0; i < V; i++) {
        free(dist[i]);
    }
    free(dist);
}
void printSolution(int **dist, int V) {
    printf("\nShortest distance matrix between every pair of vertices:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF) {
                printf("%7s", "INF");
            } else {
                printf("%7d", dist[i][j]);
            }
        }
        printf("\n");
    }
}
