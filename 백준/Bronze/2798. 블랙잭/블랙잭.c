#include <stdio.h>

#define MAX 100

int main(void) {
    int card, cards[MAX], goal, tmp, result = 0;
    scanf("%d%d", &card, &goal);
    for (int i = 0; i < card; i++) scanf("%d", &cards[i]);
    for (int i = 0; i < card; i++) {
        for (int j = i + 1; j < card; j++) {
            for (int k = j + 1; k < card; k++) {
                tmp = cards[i] + cards[j] + cards[k];
                if (result < tmp && tmp <= goal) result = tmp;
                if (result == goal) break;
            }
        }
    }
    printf("%d", result);
    return 0;
}