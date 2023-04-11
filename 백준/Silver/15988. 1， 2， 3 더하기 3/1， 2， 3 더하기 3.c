#include <stdio.h>

#define MAX 1000001
#define DIVISOR 1000000009

long long arr[MAX];

int main(void) {
    int iteration, num, filledNumber = 3;
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;
    scanf("%d", &iteration);
    for (int i = 0; i < iteration; i++) {
        scanf("%d", &num);
        for (int j = filledNumber + 1; j <= num; j++) {
            arr[j] = (arr[j - 1] + arr[j - 2] + arr[j - 3]) % DIVISOR;
        }
        filledNumber = filledNumber > num ? filledNumber : num;
        printf("%lld\n", arr[num]);
    }
    return 0;
}