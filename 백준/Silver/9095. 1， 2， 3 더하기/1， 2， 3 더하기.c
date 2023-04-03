#include <stdio.h>

int getTheNumberOfCases(int num);

int main(void) {
    int iteration, num;
    scanf("%d", &iteration);
    for (int i = 0; i < iteration; i++) {
        scanf("%d", &num);
        printf("%d\n", getTheNumberOfCases(num));
    }
    return 0;
}

int getTheNumberOfCases(int num) {
    switch(num) {
        case 1: return 1;
        case 2: return 2;
        case 3: return 4;
        default: return getTheNumberOfCases(num - 1) + getTheNumberOfCases(num - 2) + getTheNumberOfCases(num - 3);
    }
}