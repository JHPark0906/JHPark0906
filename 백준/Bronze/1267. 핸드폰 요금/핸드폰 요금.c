#include <stdio.h>

int main(void) {
    int len, time, costY = 0, costM = 0;
    scanf("%d", &len);
    for (int i = 0; i < len; i++) {
        scanf("%d", &time);
        costY += time / 30 + 1;
        costM += time / 60 + 1;
    }
    costY *= 10;
    costM *= 15;
    if (costY == costM) printf("Y M %d", costY);
    else if (costY < costM) printf("Y %d", costY);
    else printf("M %d", costM);
    return 0;
}