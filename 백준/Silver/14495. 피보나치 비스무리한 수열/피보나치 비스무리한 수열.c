#include <stdio.h>

#define MAX 117

int main(void) {
    long long fibLike[MAX] = {0};
    int num;
    fibLike[1] = 1; fibLike[2] = 1; fibLike[3] = 1;
    scanf("%d", &num);
    for (int i = 4; i <= num; i++)
        fibLike[i] = fibLike[i - 1] + fibLike[i - 3];
    printf("%lld", fibLike[num]);
    return 0;
}