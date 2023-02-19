#include <stdio.h>
#include <stdlib.h>

// 오름차순
int comp(const void *elem1, const void *elem2);

// 배열 arr[start..end] 안에 원소 num이 있으면 1, 없으면 0 반환
int search(int arr[], int num, int start, int end);

int main(void) {
    // 입력 받기
    int card, iteration, tmp;
    scanf("%d", &card);
    int *cards = (int *)malloc(sizeof(int) * card);
    for (int i = 0; i < card; i++) scanf("%d", &cards[i]);
    qsort(cards, card, sizeof(int), comp);
    // 카드 찾아서 결과 출력
    scanf("%d", &iteration);
    for (int i = 0; i < iteration; i++) {
        scanf("%d", &tmp);
        printf("%d ", search(cards, tmp, 0, card - 1));
    }
    free(cards);
    return 0;
}

int comp(const void *elem1, const void *elem2) {
    return *(int *)elem1 - *(int *)elem2;
}

int search(int arr[], int num, int start, int end) {
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