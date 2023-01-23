#include <stdio.h>

int main(void) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int input = a * b * c;
    int num[10] = {0};
    while (input) {
        num[input % 10]++;
        input /= 10;
    }
    for (int i = 0; i < 10; i++) {
        printf("%d\n", num[i]);
    }
    return 0;
}