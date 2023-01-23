#include <stdio.h>

int main(void) {
    int num;
    scanf("%d", &num);
    for (int i = 1; i <= num; i++) {
        printf("%d\n", i);
    }
    return 0;
}