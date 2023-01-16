#include <stdio.h>

int main(void) {
    int input;
    scanf("%d", &input);
    int numerator = 1, denominator = 1;
    int moveToRight = 1;
    for (int i = 0; i < input; i++) {
        if (i == input - 1) break;
        if (moveToRight) {
            if (numerator == 1) {
                denominator++;
                moveToRight = 0;
            } else {
                denominator++;
                numerator--;
            }
        } else {
            if (denominator == 1) {
                numerator++;
                moveToRight = 1;
            } else {
                numerator++;
                denominator--;
            }
        }
    }
    printf("%d/%d", numerator, denominator);
    return 0;
}