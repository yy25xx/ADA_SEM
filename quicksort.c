#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function as per the pseudocode
int partition(int arr[], int l, int h) {
    int pivot = arr[l];  // Choosing the pivot element
    int i = l;           // Starting index
    int j = h;           // Ending index

    while (i < j) {
        // Increment i while arr[i] is less than or equal to pivot
        do {
            i++;
        } while (arr[i] <= pivot);

        // Decrement j while arr[j] is greater than pivot
        do {
            j--;
        } while (arr[j] > pivot);

        // If i is still less than j, swap arr[i] and arr[j]
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }

    // Swap the pivot element with arr[j]
    swap(&arr[l], &arr[j]);
    return j;  // Return the partitioning index
}

// Recursive quicksort function
void quickSort(int arr[], int l, int h) {
    if (l < h) {
        // Partition the array and get the partition index
        int j = partition(arr, l, h);

        // Recursively sort elements before partition and after partition
        quickSort(arr, l, j);
        quickSort(arr, j + 1, h);
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

    // Seed the random number generator
    srand(time(0));

    // Input the number of elements in the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    // Generate random elements for the array
    printf("Generated array:\n");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;  // Random number between 0 and 99
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Record start time
    clock_t start = clock();

    // Perform quicksort on the array
    quickSort(arr, 0, n);

    // Record end time
    clock_t end = clock();

    // Calculate time taken in seconds
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Print the sorted array
    printf("Sorted array:\n");
    printArray(arr, n);

    // Print the time taken
    printf("Time taken to sort the array: %f seconds\n", time_taken);

    return 0;
}
