#include <stdio.h>

#define MAX_LENGTH 101
#define DIVISOR 1000000000

int main(void) {
    int len, stair[MAX_LENGTH][10] = {0}, result = 0;
    for (int i = 1; i <= 9; i++)
        stair[1][i] = 1;
    scanf("%d", &len);

    for (int i = 2; i <= len; i++) {
        stair[i][0] = stair[i - 1][1];
        for (int j = 1; j <= 8; j++)
            stair[i][j] = (stair[i - 1][j - 1] + stair[i - 1][j + 1]) % DIVISOR;
        stair[i][9] = stair[i - 1][8];
    }

    for (int i = 0; i <= 9; i++)
        result = (result + stair[len][i]) % DIVISOR;
    printf("%d", result);
    return 0;
}