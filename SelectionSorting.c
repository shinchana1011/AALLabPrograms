#include <stdio.h>

void selectionsort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minindex = i;
       
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minindex]) {
                minindex = j;
            }
        }
       
       
        if (minindex != i) {
            int temp = arr[minindex];
            arr[minindex] = arr[i];
            arr[i] = temp;
        }
    }
}

void printarray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {2, 4, 3, 1};
    int n = 4;
   
    selectionsort(arr, n);
    printarray(arr, n);
   
    return 0;
}
