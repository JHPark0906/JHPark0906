#include <stdio.h>

int rev(int n);

int main(void) {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d", rev(rev(a) + rev(b)));
    return 0;
}

int rev(int n) {
    int m = 0;
    while (n) {
        m *= 10;
        m += n % 10;
        n /= 10;
    }
    return m;
}