#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int *xp, int *yp) {
    // Use a temporary variable to perform the swap
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Function to perform selection sort
void selectionSort(int arr[], int n) {
    int i, j, minIdx;

    // Traverse through all array elements
    for (i = 0; i < n - 1; i++) {
        // Assume the current element is the minimum
        minIdx = i;

        // Find the minimum element in the unsorted part of the array
        for (j = i + 1; j < n; j++) {
            // If found a smaller element, update the minimum index
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }

        // Swap the found minimum element with the current element
        swap(&arr[minIdx], &arr[i]);
    }
}

// Function to print an array
/*void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        // Print each element followed by a space
        printf("%d ", arr[i]);
    }
    // Print a newline character at the end
    printf("\n");
}*/

int main() {
    int n;

    // Seed the random number generator with the current time
    srand(time(0));

    // Prompt the user to enter the number of elements in the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Create an array of the specified size
    int arr[n];

    // Generate random elements for the array
    printf("Generated array:\n");
    for (int i = 0; i < n; i++) {
        // Generate a random number between 0 and 99
        arr[i] = rand() % 100;
        // Print the generated number
        printf("%d ", arr[i]);
    }
    // Print a newline character after displaying the generated array
    printf("\n");

    // Record the start time before sorting
    clock_t start = clock();

    // Perform selection sort on the array
    selectionSort(arr, n);

    // Record the end time after sorting
    clock_t end = clock();

    // Calculate the time taken to sort the array in seconds
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Print the sorted array
    printf("Sorted array:\n");
    //printArray(arr, n);
    for (int i = 0; i <n; i++) {
        // Print each element followed by a space
        printf("%d ", arr[i]);
    }
    // Print a newline character at the end
    printf("\n");
    // Print the time taken to sort the array
    printf("Time taken to sort the array: %f seconds\n", time_taken);

    // Return 0 to indicate successful execution
    return 0;
}
