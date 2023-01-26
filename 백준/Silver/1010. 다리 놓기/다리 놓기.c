#include <stdio.h>

int main(void) {
    int pascal[31][31] = {0};
    pascal[0][0] = 1;
    for (int i = 1; i < 31; i++) {
        for (int j = 0; j <= i; j++) {
            if (!j || i == j) pascal[i][j] = 1;
            else pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
        }
    }
    int repetition, n, r;
    scanf("%d", &repetition);
    for (int i = 0; i < repetition; i++) {
        scanf("%d%d", &r, &n);
        printf("%d\n", pascal[n][r]);
    }
    return 0;
}