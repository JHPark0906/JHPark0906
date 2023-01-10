#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int paid, products, total = 0;
    scanf("%d%d", &paid, &products);
    int *arr = (int *) malloc(sizeof(int) * 2 * products);
    for (int i = 0; i < 2 * products; i++) {
        scanf("%d", &arr[i]);
        if (i & 1) total += arr[i - 1] * arr[i];
    }
    printf(paid == total ? "Yes" : "No");
    return 0;
}