#include <stdio.h>

void plusCycle(int *num);

int main() {
    int input, tmp;
    scanf("%d", &input);
    tmp = input;
    int cycle = 0;
    while (input != tmp || !cycle) {
        plusCycle(&tmp);
        cycle++;
    }
    printf("%d", cycle);
    return 0;
}

void plusCycle(int *num) {
    int a, b;
    a = (*num) / 10;
    b = (*num) % 10;
    (*num) = 10 * b + (a + b) % 10;
}