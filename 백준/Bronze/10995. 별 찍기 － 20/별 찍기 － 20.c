#include <stdio.h>

int main(void) {
    int size;
    scanf("%d", &size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 2 * size - 1; j++) {
           printf("%s", (i + j) % 2 ? " " : "*");
           if (i % 2 && j == 2 * size - 2) printf("*");
        }
        printf("\n");
    }
    return 0;
}