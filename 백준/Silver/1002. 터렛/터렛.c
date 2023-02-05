#include <stdio.h>

int main(void) {
    int x1, y1, r1, x2, y2, r2, iteration, result, dSquare, pSquare, mSquare;
    scanf("%d", &iteration);
    for (int i = 0; i < iteration; i++) {
        scanf("%d%d%d%d%d%d", &x1, &y1, &r1, &x2, &y2, &r2);

        if (x1 == x2 && y1 == y2) { // 두 터렛의 좌표가 동일한 경우
            if (r1 == r2) {
                if (!r1) result = 1;
                else result = -1;
            }
            else result = 0;
        } else { // 두 터렛의 좌표가 다른 경우
            dSquare = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
            pSquare = (r1 + r2) * (r1 + r2);
            mSquare = (r1 - r2) * (r1 - r2);
            if (mSquare > dSquare || dSquare > pSquare) result = 0;
            else if (mSquare == dSquare || dSquare == pSquare) result = 1;
            else if (mSquare < dSquare && dSquare < pSquare) result = 2;
        }
        printf("%d\n", result);
    }
    return 0;
}