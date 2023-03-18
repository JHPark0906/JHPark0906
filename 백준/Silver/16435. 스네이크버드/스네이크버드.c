#include <stdio.h>
#include <stdlib.h>

#define ARR_MAX 1000

int comp(const void *elem1, const void *elem2);

int main(void) {
    int num, height, arr[ARR_MAX];
    scanf("%d %d", &num, &height);
    for (int i = 0; i < num; i++) scanf("%d", &arr[i]);
    qsort(arr, num, sizeof(int), comp);
    for (int i = 0; i < num; i++) {
        if (height < arr[i]) break;
        else height++;
    }
    printf("%d", height);
    return 0;
}

int comp(const void *elem1, const void *elem2) {
    return (*(int *)elem1) - (*(int *)elem2);
}