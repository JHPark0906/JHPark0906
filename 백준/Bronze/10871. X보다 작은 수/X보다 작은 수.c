#include <stdio.h>

int main(void) {
    int len, num;
    scanf("%d%d", &len, &num);
    int input;
    for (int i = 0; i < len; i++) {
        scanf("%d", &input);
        if (input < num) printf("%d ", input);
    }
    return 0;
}