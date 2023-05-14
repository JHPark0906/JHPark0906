#include <stdio.h>

long long abs(long long n);

int main(void) {
    long long a, b;
    scanf("%lld %lld", &a, &b);
    printf("%lld", abs(a - b));
    return 0;
}

long long abs(long long n) {
    return n * (n < 0 ? -1 : 1);
}