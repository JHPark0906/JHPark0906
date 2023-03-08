#include <stdio.h>
#include <stdlib.h>

int comp(const void *elem1, const void *elem2);

int main(void) {
    int iteration, arr[10];
    scanf("%d", &iteration);
    for (int i = 0; i < iteration; i++) {
        for (int j = 0; j < 10; j++) scanf("%d", &arr[j]);
        qsort(arr, 10, sizeof(int), comp);
        printf("%d\n", arr[2]);
    }
    return 0;
}

int comp(const void *elem1, const void *elem2) {
    return (*(int *)elem2) - (*(int *)elem1);
}