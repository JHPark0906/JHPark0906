#include <stdio.h>

int main(void) {
    int size;
    scanf("%d", &size);
    size = 2 * size - 1;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (((i <= j) && (j <= size - i - 1)) || ((j <= i) && (size - i - 1 <= j))) {
                printf("*");
            } else printf(" ");
            if (((j > size - 1 - i) && (i < (size + 1) / 2)) || ((j > i) && (i >= (size + 1) / 2))) break;
        }
        printf("\n");
    }
    return 0;
}