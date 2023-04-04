#include <stdio.h>

#define ARR_MAX 301

int stair[ARR_MAX];
int max_score[ARR_MAX];
int goal;

int getMaxScore(int floor);

int main(void) {
    scanf("%d", &goal);
    stair[0] = 0;
    for (int i = 1; i <= goal; i++)
        scanf("%d", &stair[i]);
    printf("%d", getMaxScore(goal));
    return 0;
}

int getMaxScore(int floor) {
    max_score[0] = stair[0];
    max_score[1] = stair[1];
    max_score[2] = stair[1] + stair[2];
    for (int i = 3; i <= floor; i++) {
        int a = max_score[i-2] + stair[i];
        int b = max_score[i-3] + stair[i-1] + stair[i];
        max_score[i] = a > b ? a : b;
    }
    return max_score[floor];
}