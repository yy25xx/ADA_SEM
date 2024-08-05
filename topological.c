#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX]; // Adjacency matrix to represent the graph
int visited[MAX];  // Array to keep track of visited nodes
int stack[MAX];    // Stack to store the topological order
int stackIndex;    // Index for the stack

// A utility function to perform DFS
void DFS(int v, int V) {
    visited[v] = 1; // Mark the current node as visited

    // Visit all adjacent nodes
    for (int i = 0; i < V; i++) {
        if (adj[v][i] && !visited[i]) {
            DFS(i, V); // Recursively visit unvisited adjacent nodes
        }
    }

    // Push the current node to stack after all adjacent nodes are visited
    stack[stackIndex++] = v;
}

// The function to perform topological sort
void topologicalSort(int V) {
    stackIndex = 0; // Initialize stack index

    // Perform DFS for all unvisited vertices
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            DFS(i, V);
        }
    }

    // Print the nodes in topologically sorted order
    for (int i = stackIndex - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int V = n; // Number of vertices
    int E;

    // Initialize adjacency matrix and visited array
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            adj[i][j] = 0; // Initialize all edges to 0 (no edge)
        }
        visited[i] = 0; // Mark all vertices as unvisited
    }

    // Input number of edges
    printf("Enter the number of edges: ");
    scanf("%d", &E);

    // Input edges
    printf("Enter the edges (source destination):\n");
    for (int i = 0; i < E; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        // Validate edge input
        if (src >= 0 && src < V && dest >= 0 && dest < V) {
            adj[src][dest] = 1; // Set edge in the adjacency matrix
        } else {
            printf("Invalid edge: %d -> %d\n", src, dest);
        }
    }

    // Perform and print the topological sort
    printf("Topological Sort of the given graph:\n");
    topologicalSort(V);

    return 0;
}
