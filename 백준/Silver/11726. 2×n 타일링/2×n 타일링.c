#include <stdio.h>

#define DIVISOR 10007

typedef struct pair {
    int a, b;
} pair;

pair getNumOfCases(int num);

int main(void) {
    int num;
    pair result;
    scanf("%d", &num);
    result = getNumOfCases(num);
    printf("%d", result.a);
    return 0;
}

pair getNumOfCases(int num) {
    pair result, lastResult;
    switch (num) {
        case 1:
            result.a = 1; result.b = 0;
            break;
        case 2:
            result.a = 2; result.b = 1;
            break;
        default:
            lastResult = getNumOfCases(num - 1);
            result.a = (lastResult.a + lastResult.b) % DIVISOR;
            result.b = lastResult.a;
    }
    return result;
}