#include<stdio.h>
#include<stdlib.h>

int a[10][10], d[10][10], n;

// Function to return the minimum of two numbers
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to compute shortest paths using Floyd-Warshall algorithm
void path() {
    int i, j, k;
    // Iterate over all possible intermediate vertices
    for (k = 0; k < n; k++) {
        // Iterate over all pairs of source and destination vertices
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                // Update the shortest path considering the intermediate vertex k
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

int main() {
    int i, j;
    // Input number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    // Input the cost matrix
    printf("Enter the cost matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
            // Initialize the distance matrix with the cost matrix values
            d[i][j] = a[i][j];
        }
    }

    // Compute the shortest paths
    path();

    // Print the shortest path matrix
    printf("The shortest path matrix is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d\t", d[i][j]);
        }
        printf("\n");
    }

    return 0;
}
