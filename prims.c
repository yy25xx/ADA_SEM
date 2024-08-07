#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 100 // Maximum number of vertices

// Function to select the vertex with the minimum value which is not yet processed
int selectMinVertex(int value[], bool setMST[], int V) {
    int minimum = INT_MAX;
    int vertex;
    for (int i = 0; i < V; ++i) {
        if (!setMST[i] && value[i] < minimum) {
            vertex = i;
            minimum = value[i];
        }
    }
    return vertex;
}

// Function to find the Minimum Spanning Tree using Prim's Algorithm
void findMST(int graph[MAX][MAX], int V) {
    int parent[MAX];     // Stores MST
    int value[MAX];      // Used for edge relaxation
    bool setMST[MAX];    // TRUE->Vertex is included in MST

    // Initialize all values to infinity and setMST as false
    for (int i = 0; i < V; ++i) {
        value[i] = INT_MAX;
        setMST[i] = false;
    }

    // Assuming start point as Node-0
    parent[0] = -1; // Start node has no parent
    value[0] = 0;   // Start node has value=0 to get picked first

    // Form MST with (V-1) edges
    for (int i = 0; i < V - 1; ++i) {
        // Select best Vertex by applying greedy method
        int U = selectMinVertex(value, setMST, V);
        setMST[U] = true; // Include new Vertex in MST

        // Relax adjacent vertices (not yet included in MST)
        for (int j = 0; j < V; ++j) {
            /*
             * 3 constraints to relax:
             * 1. Edge is present from U to j.
             * 2. Vertex j is not included in MST.
             * 3. Edge weight is smaller than current edge weight.
             */
            if (graph[U][j] != 0 && !setMST[j] && graph[U][j] < value[j]) {
                value[j] = graph[U][j];
                parent[j] = U;
            }
        }
    }

    // Print MST
    for (int i = 1; i < V; ++i)
        printf("U->V: %d->%d  wt = %d\n", parent[i], i, graph[parent[i]][i]);
}

int main() {
    int V, E;
    int graph[MAX][MAX];

    // Input number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    // Initialize the graph matrix to 0
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            graph[i][j] = 0;
        }
    }

    // Input the adjacency matrix
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Find and print the MST
    findMST(graph, V);

    return 0;
}
