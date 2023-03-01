#include <stdio.h>

int main(void) {
    int size;
    scanf("%d", &size);
    for (int i = 0; i < 2 * size - 1; i++) {
        for (int j = 0; j < 2 * size - 1; j++) {
            if (i < size - 1) {
                if (j < size - i - 1) printf(" ");
                else if (j < size + i) printf("*");
                else break;
            } else if (i == size - 1) printf("*");
            else if (i > size - 1) {
                if (j < i - size + 1) printf(" ");
                else if (j < 3 * size - i - 2) printf("*");
                else break;
            }
        }
        printf("\n");
    }
    return 0;
}