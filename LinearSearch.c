#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int size;
clock_t start, end;

void linearsearch(int* arr, int target) {
    int count = 0;
    start = clock();

    for (int i = 0; i < size; i++) {
        count++;
        if (arr[i] == target) {
            end = clock();
            double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
            printf("\nElement found at index %d\n", i);
            printf("Iterations: %d\n", count);
            printf("Time taken: %f seconds\n", time_taken);
            return;
        }
    }
    
    printf("Element not found.\n");
}

int main() {
    printf("\nEnter the size of the array: ");
    while (scanf("%d", &size) != 1 || size <= 0) {
        printf("Invalid input. Enter a positive integer: ");
        while (getchar() != '\n'); // Clear input buffer
    }

    // Dynamic memory allocation
    int* arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    srand(time(0)); // Seed random generator once
    printf("\nGenerated Array: ");
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 2000;
        printf("%d ", arr[i]);
    }
    printf("\n");

    while (1) {
        int choice;
        printf("\nEnter 1 to search, 2 to quit: ");
        while (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2)) {
            printf("Invalid input. Enter 1 to search or 2 to quit: ");
            while (getchar() != '\n'); // Clear input buffer
        }

        if (choice == 2) {
            break;
        }

        int target;
        printf("Enter the search value: ");
        while (scanf("%d", &target) != 1) {
            printf("Invalid input. Enter a valid number: ");
            while (getchar() != '\n'); // Clear input buffer
        }

        linearsearch(arr, target);
    }

    free(arr); // Free allocated memory
    return 0;
}
