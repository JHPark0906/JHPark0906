#include <stdio.h>
#include <math.h>

int palindrome(int n);

int main(void) {
    int n;
    while (1) {
        scanf("%d", &n);
        if (!n) break;
        printf(palindrome(n) ? "yes\n" : "no\n");
    }
    return 0;
}

int palindrome(int n) {
    int log = 1 + (int)log10((double)n);
    int tmp = n, m = 0;
    for (int i = 1; i <= log; i++) {
        m += (tmp % 10) * pow(10, log - i);
        tmp /= 10;
    }
    return n == m ? 1 : 0;
}