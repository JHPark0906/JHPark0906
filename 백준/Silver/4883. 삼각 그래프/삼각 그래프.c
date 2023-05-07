#include <stdio.h>
#include <limits.h>

#define MAX 100000

int price[MAX][3];
int totalPrice[MAX][3];

void setTotalPrice(int height);
int min(int a, int b, int c, int d);

int main(void) {
    int height, cnt = 0;
    while (1) {
        scanf("%d", &height);
        if (!height)
            break;
        for (int i = 0; i < height; i++)
            scanf("%d %d %d", &price[i][0], &price[i][1], &price[i][2]);
        setTotalPrice(height);
        printf("%d. %d\n", ++cnt, totalPrice[0][1]);
    }
    return 0;
}

void setTotalPrice(int height) {
    totalPrice[height - 1][2] = INT_MAX;
    totalPrice[height - 1][1] = price[height - 1][1];
    totalPrice[height - 1][0] = price[height - 1][0] + totalPrice[height - 1][1];
    for (int i = height - 2; i >= 0; i--) {
        totalPrice[i][2] = price[i][2] + min(totalPrice[i + 1][1], totalPrice[i + 1][2], INT_MAX, INT_MAX);
        totalPrice[i][1] = price[i][1] + min(totalPrice[i][2], totalPrice[i + 1][0], totalPrice[i + 1][1], totalPrice[i + 1][2]);
        totalPrice[i][0] = price[i][0] + min(totalPrice[i][1], totalPrice[i + 1][0], totalPrice[i + 1][1], INT_MAX);
    }
}

int min(int a, int b, int c, int d) {
    return ((a < b) ? ((a < c) ? ((a < d) ? a : d) : ((c < d) ? c : d)) : ((b < c) ? ((b < d) ? b : d) : ((c < d) ? c : d)));
}