#include <stdio.h>

#define MAX 10000

int main(void) {
    long long lan, goal, length[MAX], result, min = 1, max = 0, tmp;
    scanf("%lld%lld", &lan, &goal);
    for (int i = 0; i < lan; i++) {
        scanf("%lld", &length[i]);
        if (length[i] > max) max = length[i];
    }
    while (min < max - 1) {
        tmp = (min + max) / 2;
        result = 0;
        for (int i = 0; i < lan; i++) result += length[i] / tmp;
        if (result >= goal) min = tmp;
        else max = tmp - 1;
    }
    if (min == max) tmp = min;
    else {
        result = 0;
        for (int i = 0; i < lan; i++) result += length[i] / max;
        if (result >= goal) tmp = max;
        else tmp = min;
    }
    printf("%lld", tmp);
    return 0;
}