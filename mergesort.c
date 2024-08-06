#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to merge two halves of the array
void merge(int arr[], int l, int mid, int h) {
    int i = l;       // Starting index for the left subarray
    int j = mid + 1; // Starting index for the right subarray
    int k = 0;       // Starting index for the temporary array
    int n1 = mid - l + 1; // Number of elements in the left subarray
    int n2 = h - mid;     // Number of elements in the right subarray

    // Temporary array to hold merged elements
    int* temp = (int*)malloc((n1 + n2) * sizeof(int));

    // Merge the elements from both subarrays into the temporary array
    while (i <= mid && j <= h) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++]; // If the current element in the left subarray is smaller or equal, add it to the temporary array
        } else {
            temp[k++] = arr[j++]; // If the current element in the right subarray is smaller, add it to the temporary array
        }
    }

    // Copy remaining elements from the left subarray, if any
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copy remaining elements from the right subarray, if any
    while (j <= h) {
        temp[k++] = arr[j++];
    }

    // Copy merged elements back to the original array
    for (i = l, k = 0; i <= h; i++, k++) {
        arr[i] = temp[k];
    }

    // Free the temporary array to avoid memory leaks
    free(temp);
}

// Recursive mergesort function
void mergeSort(int arr[], int l, int h) {
    if (l < h) { // Base case: if the array contains more than one element
        int mid = l + (h - l) / 2; // Find the middle point to divide the array into two halves

        // Recursively sort the first and second halves
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, h);

        // Merge the two sorted halves
        merge(arr, l, mid, h);
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

    // Seed the random number generator with the current time
    srand(time(0));

    // Input the number of elements in the array
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    // Declare an array of size n
    int arr[n];

    // Generate random elements for the array
    printf("Generated array:\n");
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Generate a random number between 0 and 99
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Record start time
    clock_t start = clock();

    // Perform mergesort on the array
    mergeSort(arr, 0, n - 1);

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
