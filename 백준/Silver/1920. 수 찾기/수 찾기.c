#include <stdio.h>
#include <stdlib.h>

// 오름차순
int comp(const void *elem1, const void *elem2);

// 배열 arr[start..end] 안에 원소 num이 있으면 1, 없으면 0 반환
int search(long long arr[], int num, int start, int end);

int main(void) {
    // 입력 받기
    int len, iteration, tmp;
    scanf("%d", &len);
    long long *arr = (long long *)malloc(sizeof(long long) * len);
    for (int i = 0; i < len; i++) scanf("%lld", &arr[i]);
    qsort(arr, len, sizeof(long long), comp);
    // 숫자 찾아서 결과 출력
    scanf("%d", &iteration);
    for (int i = 0; i < iteration; i++) {
        scanf("%d", &tmp);
        printf("%d\n", search(arr, tmp, 0, len - 1));
    }
    free(arr);
    return 0;
}

int comp(const void *elem1, const void *elem2) {
    if (*(long long *)elem1 - *(long long *)elem2 > 0) return 1;
    else if (*(long long *)elem1 - *(long long *)elem2 < 0) return -1;
    else return 0;
}

int search(long long arr[], int num, int start, int end) {
    int result;
    if (start == end) {
        if (arr[start] == num) return 1;
        else return 0;
    }
    int mid = (start + end) / 2;
    if (arr[mid] > num) result = search(arr, num, start, mid);
    else if (arr[mid] < num) result = search(arr, num, mid + 1, end);
    else return 1;
    return result;
}