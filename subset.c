#include <stdio.h>

#define MAX 100 // Define maximum size for arrays

// Function to print a subset
void printSubset(int subset[], int size) {
    // Print all elements in the subset
    for (int i = 0; i < size; i++) {
        printf("%d ", subset[i]);
    }
    printf("\n"); // Newline after printing the subset
}

// Recursive function to find subsets with a given sum
void findSubsets(int S[], int n, int d, int subset[], int subsetSize, int index) {
    // Base case: if the target sum is 0, print the current subset
    if (d == 0) {
        printSubset(subset, subsetSize);
        return; // Return after printing to avoid further processing
    }

    // Base case: if no more items to process or sum becomes negative
    if (n == 0 || d < 0) {
        return; // Exit the function if no valid subsets can be found
    }

    // Include the current item in the subset
    subset[subsetSize] = S[index]; // Add the current item to the subset
    // Recur with remaining items, reduced sum, and next index
    findSubsets(S, n - 1, d - S[index], subset, subsetSize + 1, index + 1);

    // Exclude the current item from the subset
    // No need to remove it from the subset array because it will be overwritten
    // by the next recursive call
    // Recur with remaining items and next index without including the current item
    findSubsets(S, n - 1, d, subset, subsetSize, index + 1);
}

int main() {
    int n, d;
    int S[MAX], subset[MAX]; // Arrays to store elements and current subset

    // Input number of elements in the set
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    // Input elements of the set
    printf("Enter the elements of the set:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &S[i]); // Read each element of the set
    }

    // Input the target sum
    printf("Enter the target sum: ");
    scanf("%d", &d);

    printf("Subsets with sum %d:\n", d);
    // Initialize the subset array and start recursive search
    findSubsets(S, n, d, subset, 0, 0);

    return 0; // End of the program
}
