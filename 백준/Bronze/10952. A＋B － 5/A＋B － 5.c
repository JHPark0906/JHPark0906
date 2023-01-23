#include <stdio.h>

int main(void) {
    int a = 1, b = 1;
    while (a && b) {
        scanf("%d%d", &a, &b);
        if (a && b) printf("%d\n", a + b);
    }
    return 0;
}