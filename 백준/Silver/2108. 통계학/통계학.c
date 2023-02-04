#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int comp(const void *elem1, const void *elem2);

int main(void) {
    int len, mean, median, mode, min = 4001, max = -4001, sum = 0, count[8001] = {0};
    scanf("%d", &len);
    int *arr = (int *)malloc(sizeof(int) * len);
    for (int i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
        count[arr[i] + 4000]++;
        sum += arr[i];
        if (min > arr[i]) min = arr[i];
        if (max < arr[i]) max = arr[i];
    }
    mean = (int)round((double)sum / len);
    int tmp = -1, countMax = 0;
    for (int i = 0; i < 8001; i++) if (countMax < count[i]) countMax = count[i];
    for (int i = 0; i < 8001; i++) {
        if (countMax == count[i]) {
            if (tmp != -1) {
                mode = i - 4000;
                break;
            } else tmp = i;
        }
        mode = tmp - 4000;
    }
    qsort(arr, len, sizeof(int), comp);
    median = arr[len / 2];
    printf("%d\n%d\n%d\n%d", mean, median, mode, max - min);
    free(arr);
    return 0;
}

int comp(const void *elem1, const void *elem2) {
    return (*(int *)elem1) - (*(int *)elem2);
}