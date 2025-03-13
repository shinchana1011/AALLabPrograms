#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int size;
int arr[100000];
clock_t start, end;
double sorting_time, searching_time;

void bubbleSort() {
    start = clock();
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    end = clock();
    sorting_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Sorting Time taken: %f seconds\n", sorting_time);
}

void binaryserch(int target_index) {
    int left = 0, right = size - 1, count = 0;
    start = clock();
    int target = arr[target_index];

    while (left <= right) {
        count++;
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            end = clock();
            searching_time = ((double)(end - start)) / CLOCKS_PER_SEC;
            printf("The count is %d\n", count);
            printf("Searching Time taken: %f seconds\n", searching_time);

            return;
        }
        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    printf("Element not found.\n");
}

int main() {
    printf("\nEnter the size of the array: ");
    scanf("%d", &size);

    srand(time(0));
    printf("\nGenerated Array: ");
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 2000;
    }

    bubbleSort();

    printf("\nSorted Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    while (1) {
        int choice;
        printf("Enter 1 to search or 2 to quit: ");
        scanf("%d", &choice);

        if (choice == 2) {
            break;
        } else if (choice == 1) {
            int target_index;
            printf("Enter the search index (0-based): ");
            scanf("%d", &target_index);
            if (target_index >= 0 && target_index < size) {
                binaryserch(target_index);
            } else {
                printf("Invalid index. Try again.\n");
            }
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
