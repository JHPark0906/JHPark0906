#include <stdio.h>

int main(void) {
    int num, result = 0;
    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        result += i + 1;
    }
    printf("%d", result);
    return 0;
}