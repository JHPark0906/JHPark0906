#include <stdio.h>

#define MAX 1000001

int min[MAX], num;

int getMin(int num);

int main(void) {
    scanf("%d", &num);
    printf("%d", getMin(num));
    return 0;
}

int getMin(int num) {
    if (num <= 1) return 0;
    if (min[num]) return min[num];
    int tmp, result = MAX;
    if (!(num % 3)) {
        tmp = getMin(num / 3) + 1;
        if (tmp < result) result = tmp;
    }
    if (!(num % 2)) {
        tmp = getMin(num / 2) + 1;
        if (tmp < result) result = tmp;
    }
    tmp = getMin(num - 1) + 1;
    if (tmp < result) result = tmp;
    min[num] = result;
    return result;
}