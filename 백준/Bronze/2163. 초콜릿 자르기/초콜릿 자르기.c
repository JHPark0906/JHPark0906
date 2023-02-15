#include <stdio.h>

int cutting(int x, int y);

int main(void) {
    int x, y;
    scanf("%d%d", &x, &y);
    printf("%d", cutting(x, y));
    return 0;
}

int cutting(int x, int y) {
    if (x == 1 && y == 1) return 0;
    else {
        if (x > y) {
            int tmp = x;
            x = y;
            y = tmp;
        }
        return 1 + cutting(x, y / 2) + cutting(x, y - (y / 2));
    }
}