#include <stdio.h>

void swap(int *elem1, int *elem2);

int main(void) {
    int arr[3];
    for (int i = 0; i < 3; i++) scanf("%d", &arr[i]);
    if (arr[0] > arr[1]) swap(&arr[0], &arr[1]);
    if (arr[1] > arr[2]) swap(&arr[1], &arr[2]);
    if (arr[0] > arr[1]) swap(&arr[0], &arr[1]);
    for (int i = 0; i < 3; i++) printf("%d ", arr[i]);
    return 0;
}

void swap(int *elem1, int *elem2) {
    int tmp;
    tmp = *elem1;
    *elem1 = *elem2;
    *elem2 = tmp;
}