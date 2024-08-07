#include <stdio.h>

#define MAX 10   // Maximum number of nodes
#define INF 999  // Represents an infinite cost for no connection

int parent[MAX]; // Array to store the parent of each node

// Function to find the root of a node
/*int find(int i);

// Function to unite two subsets
void uni(int i, int j);*/

// Function to implement Kruskal's algorithm for finding the Minimum Spanning Tree (MST)
void kruskal(int n, int cost[MAX][MAX]);

int main() {
    int cost[MAX][MAX], n;

    // Input the number of nodes
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    
    // Input the cost matrix
    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            // Replace 0 with INF (no connection) except on the diagonal
            if (cost[i][j] == 0 ) {
                cost[i][j] = INF;
            }
        }
    }

    // Initialize parent array for union-find
    for (int i = 0; i < n; i++) {
        parent[i] = -1;
    }

    // Call Kruskal's algorithm
    kruskal(n, cost);

    return 0;
}

// Function to implement Kruskal's algorithm
void kruskal(int n, int cost[MAX][MAX]) {
    int a, b, u, v, i, j, ne = 1, min, mincost = 0;

    printf("The edges of minimum cost spanning tree are:\n");

    // Loop until we include n-1 edges in the MST
    while (ne < n) {
        // Find the minimum cost edge
        for (i = 0, min = INF; i < n; i++) {
            for (j = 0; j < n; j++) {
                // Check if the edge is the smallest and not already considered
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        // Find the roots of the nodes
        u = find(u);
        v = find(v);

        // If u and v are in different subsets, include the edge in the MST
        if (u != v) {
            uni(u, v);       // Union the subsets
            ne++;            // Increment the edge count in MST
            printf("Edge (%d, %d) = %d\n", a, b, min);
            mincost += min;  // Add the edge cost to the total cost
        }

        // Remove the edge from the graph
        cost[a][b] = cost[b][a] = INF;
    }

    // Print the minimum cost of the spanning tree
    printf("\nMinimum cost = %d\n", mincost);
}

// Function to find the root of a node using path compression
int find(int i) {
    while (parent[i] >= 0) {
        i = parent[i];
    }
    return i;
}

// Function to unite two subsets
void uni(int i, int j) {
    parent[j] = i;
}
