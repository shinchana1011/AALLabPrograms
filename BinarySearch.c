#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to perform binary search
int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; // Key not found
}

// Function to generate a sorted random array
void generateSortedArray(int arr[], int n) {
    arr[0] = rand() % 10; // Start with a small random number
    for (int i = 1; i < n; i++) {
        arr[i] = arr[i - 1] + (rand() % 10 + 1); // Ensure sorted order
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, key;
    
    // Seed the random number generator
    srand(time(0));

    // Get array size from user
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n]; // Declare array of size n

    // Generate and print a sorted random array
    generateSortedArray(arr, n);
    printf("Generated sorted array: ");
    printArray(arr, n);

    // Get the search key from user
    printf("Enter the element to search: ");
    scanf("%d", &key);

    // Perform binary search
    int result = binarySearch(arr, 0, n - 1, key);

    // Print search result
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}
