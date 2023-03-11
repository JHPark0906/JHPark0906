#include <stdio.h>

#define MAX 3037000500
#define square(x) ((x) * (x))

long long root(long long num);

int main(void) {
    long long num;
    scanf("%lld", &num);
    printf("%lld", root(num));
    return 0;
}

long long root(long long num) {
    if (num <= 1) return num;
    long long start = 0, end = num;
    long long tmp = (num + start) / 2;
    while (start < end) {
        if (end - start == 1 && square(start) < num) return end;
        if (tmp >= MAX) {
            end = tmp;
        } else if (square(tmp) > num) {
            end = tmp;
        } else {
            start = tmp;
        }
        tmp = (start + end) / 2;
        if (tmp < MAX && square(tmp) == num) return tmp;
    }
    return tmp;
}