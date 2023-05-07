#include <stdio.h>

#define MAX 51
#define DIVISOR 1000000007

int main(void) {
    int num, fibCall[MAX];
    fibCall[0] = 1; fibCall[1] = 1;
    scanf("%d", &num);
    for (int i = 2; i <= num; i++)
        fibCall[i] = (1 + fibCall[i - 1] + fibCall[i - 2]) % DIVISOR;
    printf("%d", fibCall[num]);
    return 0;
}