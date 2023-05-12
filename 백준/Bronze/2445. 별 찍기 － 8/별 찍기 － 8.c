#include <stdio.h>
#include <stdbool.h>

void printStar(int size);
bool star(int size, int i, int j);

int main(void) {
    int size;
    scanf("%d", &size);
    printStar(size);
    return 0;
}

void printStar(int size) {
    for (int i = 0; i < 2 * size - 1; i++) {
        for (int j = 0; j < 2 * size; j++) {
            if (star(size, i, j))
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

bool star(int size, int i, int j) {
    if ((i < size - 1 && j - i >= 1 && j + i <= 2 * size - 2) || (i >= size && j <= i && i + j >= 2 * size - 1))
        return false;
    return true;
}