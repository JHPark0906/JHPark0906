#include <stdio.h>

#define MAX 36

int main(void) {
    long long t[MAX];
    t[0] = 1;
    int num;
    scanf("%d", &num);

    for (int i = 1; i <= num; i++) {
        t[i] = 0;
        for (int j = 0; j < i; j++) {
            t[i] += t[j] * t[i - j - 1];
        }
    }

    printf("%lld", t[num]);
    return 0;
}