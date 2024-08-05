#include <stdio.h>
#include <stdlib.h>

// Macro to find the maximum of two values
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main() {
    int n;  // Number of items
    int m;  // Knapsack capacity

    // Input number of items
    printf("Enter the number of items: ");
    scanf("%d", &n);

    // Input knapsack capacity
    printf("Enter the knapsack capacity: ");
    scanf("%d", &m);

    // Dynamically allocate arrays for profits and weights based on number of items
    int P[n + 1];  // Profit array, indexed from 1 to n
    int wt[n + 1]; // Weight array, indexed from 1 to n
    int k[n + 1][m + 1]; // DP table to store maximum profits

    // Input profits for each item
    printf("Enter the profits for %d items:\n", n);
    for (int i = 1; i <= n; i++) {
        printf("Profit of item %d: ", i);
        scanf("%d", &P[i]);
    }

    // Input weights for each item
    printf("Enter the weights for %d items:\n", n);
    for (int i = 1; i <= n; i++) {
        printf("Weight of item %d: ", i);
        scanf("%d", &wt[i]);
    }

    // Initialize the DP table
    // k[i][w] will be the maximum profit for the first i items and capacity w
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= m; w++) {
            if (i == 0 || w == 0) {
                // Base case: No items or zero capacity results in zero profit
                k[i][w] = 0;
            } else if (wt[i] <= w) {
                // If the weight of the current item is less than or equal to the capacity
                // Calculate the maximum of including or excluding the current item
                k[i][w] = MAX(P[i] + k[i-1][w-wt[i]], k[i-1][w]);
            } else {
                // If the weight of the current item is more than the capacity, exclude the item
                k[i][w] = k[i-1][w];
            }
        }
    }

    // Print the knapsack DP table
    printf("\nKnapsack Table:\n");
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= m; w++) {
            // Print each entry in the DP table with a tab for formatting
            printf("%d\t", k[i][w]);
        }
        printf("\n"); // Newline after each row
    }

    // Print the maximum profit that can be obtained with the given items and capacity
    printf("\nMaximum profit: %d\n", k[n][m]);

    return 0;
}
