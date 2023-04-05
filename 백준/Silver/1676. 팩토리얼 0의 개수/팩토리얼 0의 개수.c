#include <stdio.h>

int getZero(int num);
int getTwo(int num);
int getFive(int num);

int main(void) {
    int num;
    scanf("%d", &num);
    printf("%d", getZero(num));
    return 0;
}

int getZero(int num) {
    if (num <= 2) return 0;
    int two = 0, five = 0;
    for (int i = 2; i <= num; i++) {
        two += getTwo(i);
        five += getFive(i);
    }
    return two < five ? two : five;
}

int getTwo(int num) {
    int result = 0;
    while (num > 1) {
        if (!(num % 2)) result++;
        else break;
        num /= 2;
    }
    return result;
}

int getFive(int num) {
    int result = 0;
    while (num > 4) {
        if (!(num % 5)) result++;
        else break;
        num /= 5;
    }
    return result;
}