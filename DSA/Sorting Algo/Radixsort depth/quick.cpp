#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void quickSort(int arr[], int low, int high, int digit) {
    if (low < high) {
        int pivot = (arr[low] / digit) % 10;
        int i = low - 1, j = high + 1;
        while (1) {
            do {
                i++;
            } while ((arr[i] / digit) % 10 < pivot);
            do {
                j--;
            } while ((arr[j] / digit) % 10 > pivot);
            if (i >= j)
                break;
            swap(&arr[i], &arr[j]);
        }
        quickSort(arr, low, j, digit);
        quickSort(arr, j + 1, high, digit);
    }
}

void radixSort(int arr[], int n) {
    int m = getMax(arr, n);
    int digit = 1;
    while (m / digit > 0) {
        quickSort(arr, 0, n - 1, digit);
        digit *= 10;
    }
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr)/sizeof(arr[0]);

    clock_t start = clock();
    radixSort(arr, n);
    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    printf("Sorted Array: \n");
    for (int i=0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\nExecution Time: %lf seconds\n", time_taken);
    return 0;
}
