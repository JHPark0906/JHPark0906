#include <stdio.h>
#include <stdbool.h>

void printStar(int size);
bool isStar(int size, int i, int j);

int main(void) {
    int size;
    scanf("%d", &size);
    printStar(size);
    return 0;
}

void printStar(int size) {
    for (int i = 0; i < 2 * size - 1; i++) {
        for (int j = 0; j < size; j++) {
            if (isStar(size, i, j))
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

bool isStar(int size, int i, int j) {
    if ((i < size && i + j < size - 1) || (i >= size && i - j >= size))
        return false;
    return true;
}