#include <stdio.h>

int isPowerOfTwo(int num);

int main(void) {
    int num;
    scanf("%d", &num);
    printf("%d", isPowerOfTwo(num));
    return 0;
}

int isPowerOfTwo(int num) {
    if (num == 1) return 1;
    else if (num % 2) return 0;
    else return isPowerOfTwo(num / 2);
}