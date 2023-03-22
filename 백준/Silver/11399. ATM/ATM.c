#include <stdio.h>
#include <stdlib.h>

#define ARR_MAX 1000

int getMinimum(int num, int arr[ARR_MAX]);
int comp(const void *elem1, const void *elem2);

int main(void) {
    int num, arr[ARR_MAX];
    scanf("%d", &num);
    for (int i = 0; i < num; i++) scanf("%d", &arr[i]);
    printf("%d", getMinimum(num, arr));
    return 0;
}

int getMinimum(int num, int arr[ARR_MAX]) {
    int sum[ARR_MAX], result = 0;
    qsort(arr, num, sizeof(int), comp);
    sum[0] = arr[0];
    result += sum[0];
    for (int i = 1; i < num; i++) {
        sum[i] = sum[i - 1] + arr[i];
        result += sum[i];
    }
    return result;
}

int comp(const void *elem1, const void *elem2) {
    return (*(int *)elem1) - (*(int *)elem2);
}