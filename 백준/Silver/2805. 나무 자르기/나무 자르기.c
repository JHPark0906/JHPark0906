#include <stdio.h>
#include <stdlib.h>

// 내림차순
int comp(const void *elem1, const void *elem2);

// 칼날의 높이가 height일 때 얼마만큼의 나무를 가져갈 수 있는지 계산
long long getTrees(int trees[], int tree, int height);

int main(void) {
    // 입력 받기
    int tree, want, height, start, end;
    long long tmp;
    scanf("%d%d", &tree, &want);
    int *trees = (int *)malloc(sizeof(int) * tree);
    for (int i = 0; i < tree; i++) scanf("%d", &trees[i]);
    qsort(trees, tree, sizeof(int), comp);

    // 칼날의 높이를 이분탐색으로 바꿔가면서 확인
    start = 0; end = trees[0];
    while (1) {
        if (start == end) {
            printf("%d", start);
            break;
        } else if (start == end - 1) {
            printf("%d", getTrees(trees, tree, end) > want ? end : start);
            break;
        }
        height = (start + end) / 2;
        tmp = getTrees(trees, tree, height);
        if (tmp == want) {
            printf("%d", height);
            break;
        }
        else if (tmp > want) start = height;
        else if (tmp < want) end = height;
    }
    free(trees);
    return 0;
}

int comp(const void *elem1, const void *elem2) {
    return *(int *)elem2 - *(int *)elem1;
}

long long getTrees(int trees[], int tree, int height) {
    long long result = 0;
    for (int i = 0; i < tree; i++) {
        if (trees[i] >= height)
            result += trees[i] - height;
        else break;
    }
    return result;
}