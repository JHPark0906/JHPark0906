#include <stdio.h>

int digitSum(int n);

int main(void) {
    int input, output = 0;
    scanf("%d", &input);
    for (int i = 1; i <= input; i++) {
        if (digitSum(i) == input) {
            output = i;
            break;
        }
    }
    printf("%d", output);
    return 0;
}

int digitSum(int n) {
    int output = n;
    while (n) {
        output += n % 10;
        n /= 10;
    }
    return output;
}