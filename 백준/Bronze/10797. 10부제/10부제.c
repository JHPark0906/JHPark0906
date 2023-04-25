#include <stdio.h>

int main(void) {
    int illegal, tmp, illegal_car = 0;
    scanf("%d", &illegal);
    for (int i = 0; i < 5; i++) {
        scanf("%d", &tmp);
        if (tmp == illegal)
            illegal_car++;
    }
    printf("%d", illegal_car);
    return 0;
}