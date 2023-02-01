#include <stdio.h>

int main(void) {
    int combination[11][11] = {0};
    combination[0][0] = 1;
    for (int i = 1; i < 11; i++) {
        combination[i][0] = 1;
        for (int j = 1; j <= i; j++) combination[i][j] = combination[i - 1][j - 1] + combination[i - 1][j];
    }
    int n, r;
    scanf("%d%d", &n, &r);
    printf("%d", combination[n][r]);
    return 0;
}