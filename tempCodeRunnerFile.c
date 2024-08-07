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
