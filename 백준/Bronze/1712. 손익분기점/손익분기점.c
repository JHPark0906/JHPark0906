#include <stdio.h>

int main(void) {
    int fixedCost, variableCost, price;
    int result;
    scanf("%d%d%d", &fixedCost, &variableCost, &price);
    if (variableCost >= price) {
        printf("-1");
        return 0;
    }
    result = fixedCost / (price - variableCost) + 1;
    printf("%d", result);
    return 0;
}