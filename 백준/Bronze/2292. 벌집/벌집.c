#include <stdio.h>

int main(void) {
    int input, result = 1;
    int num = 1;
    scanf("%d", &input);

    while (input > 1) {
        result++;
        input -= 6 * num;
        num++;
    }

    printf("%d", result);
    return 0;
}