#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 50

int main() {
    int V;
    int graph[MAX_VERTICES][MAX_VERTICES];
    
    int parent[MAX_VERTICES]; 
    int key[MAX_VERTICES]; 
    int mstSet[MAX_VERTICES];  

    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph[i][j] = 0;
        }
    }

    int E;
    printf("Enter the number of edges: ");
    scanf("%d", &E);
    
    printf("Enter edge details (Source Destination Weight):\n");
    for (int i = 0; i < E; i++) {
        int u, v, w;
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &u, &v, &w);
        
        graph[u][v] = w;
        graph[v][u] = w;
    }

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1; 

    for (int count = 0; count < V - 1; count++) {
        
        int min = INT_MAX, u = -1;
        for (int v = 0; v < V; v++) {
            if (mstSet[v] == 0 && key[v] < min) {
                min = key[v];
                u = v;
            }
        }

        if (u != -1) {
            mstSet[u] = 1;
        } else {
            break; 
        }

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    printf("\n---Minimum Spanning Tree (Prim's)---\n");
    printf("Edges included in MST:\n");
    int total_cost = 0;
    
    for (int i = 1; i < V; i++) {
        if (parent[i] != -1) {
            printf("%d--%d = %d\n", parent[i], i, graph[i][parent[i]]);
            total_cost += graph[i][parent[i]];
        }
    }
    
    printf("Total cost of MST: %d\n", total_cost);
    return 0;
}
