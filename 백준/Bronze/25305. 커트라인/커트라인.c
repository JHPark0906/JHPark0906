#include <stdio.h>
#include <stdlib.h>

void quicksort(int arr[], int row, int high);

int main(void) {
    int student, cut;
    scanf("%d%d", &student, &cut);
    int *score = (int *)malloc(sizeof(int) * student);
    for (int i = 0; i < student; i++) {
        scanf("%d", &score[i]);
    }
    quicksort(score, 0, student - 1);
    printf("%d", score[student - cut]);
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