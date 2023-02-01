#include <stdio.h>
#include <math.h>

int gcd(int a, int b);
int lcm(int a, int b);

int main(void) {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n%d", gcd(a, b), lcm(a, b));
    return 0;
}

int gcd(int a, int b) {
    int r = a % b;
    if (!r) return b;
    return gcd(b, r);
}

int lcm(int a, int b) {
    return abs(a * b) / gcd(a, b);
}