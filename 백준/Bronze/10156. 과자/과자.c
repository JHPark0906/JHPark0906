#include <stdio.h>

int main(void) {
    int price, num, money;
    scanf("%d%d%d", &price, &num, &money);
    printf("%d", price * num - money > 0 ? price * num - money : 0);
    return 0;
}