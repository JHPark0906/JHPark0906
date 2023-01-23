#include <stdio.h>

int main(void) {
    int x, y, w, h;
    scanf("%d%d%d%d", &x, &y, &w, &h);
    int d[4];
    d[0] = x; d[1] = y; d[2] = w - x; d[3] = h - y;
    int result = d[0];
    for (int i = 0; i < 4; i++) {
        if (d[i] < result) result = d[i];
    }
    printf("%d", result);
    return 0;
}