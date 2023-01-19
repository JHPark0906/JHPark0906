#include <stdio.h>

int selfNumber(int n);

int main(void) {
    for (int i = 1; i <= 10000; i++) {
        if (selfNumber(i)) {
            printf("%d\n", i);
        }
    }
    return 0;
}

int selfNumber(int n) {
    int num, tmp;
    for (int i = 1; i < n; i++) {
        num = i;
        tmp = i;
        while (tmp > 0) {
            num += tmp % 10;
            tmp = (tmp - tmp % 10) / 10;
        }
        if (num == n) return 0;
    }
    return 1;
}