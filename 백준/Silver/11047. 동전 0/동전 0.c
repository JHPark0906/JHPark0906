#include <stdio.h>
#include <stdlib.h>

int comp(const void *elem1, const void *elem2);
int getCoins(int coin[10], int coins, int money, int start);

int main(void) {
    int coins, money, coin[10];
    scanf("%d%d", &coins, &money);
    for (int i = 0; i < coins; i++) scanf("%d", &coin[i]);
    qsort(coin, coins, sizeof(int), comp);
    printf("%d", getCoins(coin, coins, money, 0));
    return 0;
}

int comp(const void *elem1, const void *elem2) {
    return (*(int *)elem2) - (*(int *)elem1);
}

int getCoins(int coin[10], int coins, int money, int start) {
    if (start > coins) return -1;
    int highest, leftMoney, tmp;
    highest = money / coin[start];
    leftMoney = money - highest * coin[start];
    if (!leftMoney) return highest;
    tmp = getCoins(coin, coins, leftMoney, start + 1);
    while (tmp == -1) {
        if (highest <= 0) return -1;
        highest--;
        leftMoney = money - highest * coin[start];
        tmp = getCoins(coin, coins, leftMoney, start + 1);
        if (tmp != -1) {
            return highest + tmp;
        }
    }
    return highest + tmp;
}