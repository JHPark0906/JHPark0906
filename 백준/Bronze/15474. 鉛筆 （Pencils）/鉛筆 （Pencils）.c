#include <stdio.h>

int main(void) {
    int goal, set_a, price_a, total_price_a, set_b, price_b, total_price_b;
    scanf("%d %d %d %d %d", &goal, &set_a, &price_a, &set_b, &price_b);
    total_price_a = (goal / set_a + (goal % set_a ? 1 : 0)) * price_a;
    total_price_b = (goal / set_b + (goal % set_b ? 1 : 0)) * price_b;
    printf("%d", total_price_a < total_price_b ? total_price_a : total_price_b);
    return 0;
}