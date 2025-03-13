
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int length, i, j, temp, count = 0;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &length);
    int a[length];
    
    srand(time(0));

    for (i = 0; i < length; i++) {
        a[i] = rand() % 100;
    }
    printf("array before bubble sort:\n");
    
    for (i = 0; i < length; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    start = clock();  
    
    for (i = 0; i < length; i++) {
        for (j = 0; j < length - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                count++;
            }
        }
    }
    
    end = clock();
    
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\narray after bubble sort:");
    
    
    for (i = 0; i < length; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    
    printf("Count: %d\n", count);
    printf("Time taken for bubble sort: %f seconds\n", cpu_time_used);

    return 0;
}
