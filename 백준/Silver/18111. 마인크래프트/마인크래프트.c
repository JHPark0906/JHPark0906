#include <stdio.h>

#define MAX 500
#define INT_MAX 2147483647

int main(void) {
    int arr[MAX][MAX], x, y, min = 256, max, num, sum = 0, time, tmp, block, minTime = INT_MAX, height;
    scanf("%d%d%d", &x, &y, &num);
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            scanf("%d", &arr[i][j]);
            if (min > arr[i][j]) min = arr[i][j];
            sum += arr[i][j];
        }
    }
    max = (sum + num) / (x * y);
    for (int h = max; h >= min; h--) {
        time = 0; tmp = 0; block = num;
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                if (arr[i][j] > h) {
                    time += 2 * (arr[i][j] - h);
                    block += arr[i][j] - h;
                }
                else tmp += h - arr[i][j];
            }
        }
        if (tmp <= block) {
            if (time + tmp < minTime) {
                minTime = time + tmp;
                height = h;
            }
        }
    }
    printf("%d %d", minTime, height);
    return 0;
}