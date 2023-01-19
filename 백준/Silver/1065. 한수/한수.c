#include <stdio.h>

int hansu(int n);

int main(void) {
    int input, result = 0;
    scanf("%d", &input);
    for (int i = 1; i <= input; i++) if (hansu(i)) result++;
    printf("%d", result);
    return 0;
}

int hansu(int n) {
    if (n < 100) return 1;
    int d, tmp1, tmp2;
    tmp1 = n % 10;
    n /= 10;
    tmp2 = n % 10;
    d = tmp1 - tmp2;
    while (n >= 10) {
        tmp1 = n % 10;
        n /= 10;
        tmp2 = n % 10;
        if (tmp1 - tmp2 != d) return 0;
    }
    return 1;
}