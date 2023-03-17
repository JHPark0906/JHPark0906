#include <stdio.h>
#include <stdlib.h>

#define ARR_MAX 100001

int comp(const void *elem1, const void *elem2);

int main(void) {
    int len, num, arr[ARR_MAX], sum[ARR_MAX], sumOfNum[ARR_MAX];
    scanf("%d %d", &len, &num);
    for (int i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
        if (!i) sum[i] = arr[i];
        else sum[i] = sum[i - 1] + arr[i];
    }
    for (int i = 0; i < len - num + 1; i++) {
        if (!i) sumOfNum[i] = sum[num - 1];
        else sumOfNum[i] = sum[i + num - 1] - sum[i - 1];
    }
    qsort(sumOfNum, len - num + 1, sizeof(int), comp);
    printf("%d", sumOfNum[0]);
    return 0;
}

int comp(const void *elem1, const void *elem2) {
    return (*(int *)elem2) - (*(int *)elem1);
}