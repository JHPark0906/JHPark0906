#include <stdio.h>

int main(void) {
    int iteration, num, tmp, sum;
    scanf("%d", &iteration);
    for (int i = 0; i < iteration; i++) {
        scanf("%d", &num);
        sum = 0;
        for (int j = 0; j < num; j++) {
            scanf("%d", &tmp);
            sum += tmp;
        }
        printf("%d\n", sum);
    }
    return 0;
}