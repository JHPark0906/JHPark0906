#include <stdio.h>

void quicksort(int arr[], int row, int high);

int main(void) {
    int arr[5];
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    quicksort(arr, 0, 4);
    printf("%d\n%d", sum / 5, arr[2]);
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