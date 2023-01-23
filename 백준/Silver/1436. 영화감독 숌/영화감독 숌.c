#include <stdio.h>

int end(int n);
int isEndNum(int n);

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%d", end(n));
    return 0;
}

int end(int n) {
    if (n == 1) return 666;
    int tmp, lastEndNum = end(n - 1);
    int i = 0, add[12] = {1, 10, 94, 97, 100, 334, 667, 934, 967, 994, 997, 1000};
    while (1) {
        tmp = lastEndNum + add[i];
        if (isEndNum(tmp)) return tmp;
        i++;
    }
}

int isEndNum(int n) {
    int count = 0;
    while (n) {
        if (n % 10 == 6) count++;
        else count = 0;
        if (count == 3) return 1;
        n /= 10;
    }
    return 0;
}