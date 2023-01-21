#include <stdio.h>
#include <stdlib.h>

void quicksort(int arr[], int row, int high);

int main(void) {
    int len;
    scanf("%d", &len);
    int *arr = (int *)malloc(sizeof(int) * len);
    for (int i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
    }
    quicksort(arr, 0, len - 1);
    for (int i = 0; i < len; i++) {
        printf("%d\n", arr[i]);
    }
    free(arr);
    return 0;
}

void quicksort(int arr[], int low, int high) {
    if (low >= high) return;
    int pivot = arr[low];
    int i = low, j = high;
    int tmp;
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }
    if (low < j) quicksort(arr, low, j);
    if (high > i) quicksort(arr, i, high);
}