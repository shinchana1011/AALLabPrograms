#include <stdio.h>

void insertionSorting(int array[], int size) {
    for (int i = 1; i < size; i++) {
        int key = array[i];
        int j = i - 1;

        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

void printArrays(int array[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int main() {
    int data[] = {20,10,40,30,60,50,70};
    int size = sizeof(data) / sizeof(data[0]);

    printf("Original array:\n");
    printArrays(data, size);

    insertionSorting(data, size);

    printf("Sorted array in ascending order:\n");
    printArrays(data, size);

    return 0;
}
