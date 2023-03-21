#include <stdio.h>

int main(void) {
    int b1, b2, b3, d1, d2;
    scanf("%d%d%d%d%d", &b1, &b2, &b3, &d1, &d2);
    printf("%d", (b1 < b2 ? (b1 < b3 ? b1 : b2 < b3 ? b2 : b3) : b2 < b3 ? b2 : b1 < b3 ? b1 : b3) + (d1 < d2 ? d1 : d2) - 50);
    return 0;
}