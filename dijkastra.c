#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 6 // Number of vertices

// Function to select the vertex with the minimum value which is not yet processed
int selectMinVertex(int value[], int processed[]) {
    int minimum = INT_MAX;
    int vertex;
    for (int i = 0; i < V; ++i) {
        if (processed[i] == 0 && value[i] < minimum) {
            vertex = i;
            minimum = value[i];
        }
    }
    return vertex;
}

// Function to implement Dijkstra's algorithm
void dijkstra(int graph[V][V]) {
    int parent[V]; // Stores shortest path structure
    int value[V]; // Keeps shortest path values to each vertex from source
    int processed[V]; // TRUE->Vertex is processed

    // Initialize all values to infinity and processed[] as false
    for (int i = 0; i < V; ++i) {
        value[i] = INT_MAX;
        processed[i] = 0;
    }

    // Assuming start point as Node-0
    parent[0] = -1; // Start node has no parent
    value[0] = 0; // Start node has value=0 to get picked first

    // Include (V-1) edges to cover all V-vertices
    for (int i = 0; i < V - 1; ++i) {
        // Select best Vertex by applying greedy method
        int U = selectMinVertex(value, processed);
        processed[U] = 1; // Include new Vertex in shortest path graph

        // Relax adjacent vertices (not yet included in shortest path graph)
        for (int j = 0; j < V; ++j) {
            /* 3 conditions to relax:-
                  1. Edge is present from U to j.
                  2. Vertex j is not included in shortest path graph.
                  3. Edge weight is smaller than current edge weight.
            */
            if (graph[U][j] != 0 && processed[j] == 0 && value[U] != INT_MAX
                && (value[U] + graph[U][j] < value[j])) {
                value[j] = value[U] + graph[U][j];
                parent[j] = U;
            }
        }
    }

    // Print Shortest Path Graph
    for (int i = 1; i < V; ++i)
        printf("U->V: %d->%d  wt = %d\n", parent[i], i, graph[parent[i]][i]);
}

int main() {
    int graph[V][V] = { {0, 1, 4, 0, 0, 0},
                        {1, 0, 4, 2, 7, 0},
                        {4, 4, 0, 3, 5, 0},
                        {0, 2, 3, 0, 4, 6},
                        {0, 7, 5, 4, 0, 7},
                        {0, 0, 0, 6, 7, 0} };

    dijkstra(graph);
    return 0;
}
