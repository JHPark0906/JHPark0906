#include <stdio.h>

int main(void) {
    long long a, b, sum;
    scanf("%lld%lld", &a, &b);
    if (a > b) {
        long long tmp = a;
        a = b;
        b = tmp;
    }
    long long s = a + b;
    long long n = b - a + 1;
    sum = s * (n / 2) + (n % 2 ? s / 2 : 0);
    printf("%lld", sum);
    return 0;
}