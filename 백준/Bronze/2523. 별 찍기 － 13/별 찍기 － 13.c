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
        for (int j = 0; j < size; j++) {
            if (star(size, i, j))
                printf("*");
            else {
                printf(" ");
                break;
            }
        }
        printf("\n");
    }
}

bool star(int size, int i, int j) {
    if ((i < size && j > i) || (i >= size && j > 2 * size - 2 - i))
        return false;
    return true;
}