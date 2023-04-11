#include <stdio.h>

#define MAX 1001
#define DIVISOR 10007

int binom[MAX][MAX];

int main(void) {
    int n, k;
    binom[1][0] = 1; binom[1][1] = 1;
    scanf("%d%d", &n, &k);
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            binom[i][j] = (binom[i - 1][j - 1] + binom[i - 1][j]) % DIVISOR;
        }
    }
    printf("%d", binom[n][k]);
    return 0;
}