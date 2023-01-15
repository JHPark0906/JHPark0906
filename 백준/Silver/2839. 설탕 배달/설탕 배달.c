#include <stdio.h>

int main() {
    int input, sugar, result;
    scanf("%d", &input);
    int repeat = input / 5;
    for (int i = 0; i <= repeat; i++) {
        sugar = input;
        result = (sugar / 5) - i;
        sugar -= 5 * ((sugar / 5) - i);
        result += (sugar / 3);
        sugar -= 3 * (sugar / 3);
        if (sugar == 0) {
            break;
        }
        if (i == repeat&& sugar != 0) {
            result = -1;
        }
    }
    printf("%d", result);
    return 0;
}