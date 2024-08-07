#include <stdio.h>
#include <limits.h>

#define MAX 100 // Maximum number of vertices

// Function to select the vertex with the minimum value which is not yet processed
int selectMinVertex(int value[], int processed[], int V) {
    int minimum = INT_MAX;
    int vertex = -1;
    for (int i = 0; i < V; ++i) {
        if (!processed[i] && value[i] < minimum) {
            vertex = i;
            minimum = value[i];
        }
    }
    return vertex;
}

// Function to implement Dijkstra's algorithm
void dijkstra(int cost[MAX][MAX], int V, int source) {
    int parent[MAX];  // Stores shortest path structure
    int value[MAX];   // Keeps shortest path values to each vertex from source
    int processed[MAX];  // TRUE->Vertex is processed

    // Initialize all values to infinity and processed[] as false
    for (int i = 0; i < V; ++i) {
        value[i] = INT_MAX;
        processed[i] = 0;
    }

    // Initialize the source node
    parent[source] = -1;  // Start node has no parent
    value[source] = 0;    // Start node has value=0 to get picked first

    // Include (V-1) edges to cover all V-vertices
    for (int i = 0; i < V - 1; ++i) {
        // Select best Vertex by applying greedy method
        int U = selectMinVertex(value, processed, V);
        processed[U] = 1;  // Include new Vertex in shortest path cost

        // Relax adjacent vertices (not yet included in shortest path cost)
        for (int j = 0; j < V; ++j) {
            /* 3 conditions to relax:-
                  1. Edge is present from U to j.
                  2. Vertex j is not included in shortest path cost.
                  3. Edge weight is smaller than current edge weight.
            */
            if (cost[U][j] != 0 && !processed[j] && value[U] != INT_MAX && (value[U] + cost[U][j] < value[j])) {
                value[j] = value[U] + cost[U][j];
                parent[j] = U;
            }
        }
    }

    // Print Shortest Path cost
    for (int i = 0; i < V; ++i) {
        if (i != source) {
            printf("U->V: %d->%d  wt = %d\n", parent[i], i, cost[parent[i]][i]);
        }
    }
}

int main() {
    int V;
    int cost[MAX][MAX]; // Declare the cost with a fixed size

    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    printf("Enter the cost matrix:\n");
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            scanf("%d", &cost[i][j]);
        }
    }

    int source;
    printf("Enter the source vertex: ");
    scanf("%d", &source);

    dijkstra(cost, V, source);

    return 0;
}
