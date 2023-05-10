#include <stdio.h>

void printStar(int size);

int main(void) {
    int size;
    scanf("%d", &size);
    printStar(size);
    return 0;
}

void printStar(int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 2 * size - i - 1; j++) {
            if (j < i)
                printf(" ");
            else
                printf("*");
        }
        printf("\n");
    }
}