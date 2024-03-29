#include <stdio.h>

int getOrderOfVisits(int size, int row, int column);

int main(void) {
    int size, row, column;
    scanf("%d%d%d", &size, &row, &column);
    printf("%d", getOrderOfVisits(size, row, column));
    return 0;
}

int getOrderOfVisits(int size, int row, int column) {
    if (size <= 1) return 2 * row + column;
    else {
        int result = 0;
        if (row >= 1 << (size - 1)) result += 1 << (2 * size - 1);
        if (column >= 1 << (size - 1)) result += 1 << (2 * size - 2);
        return result + getOrderOfVisits(size - 1, row % (1 << (size - 1)), column % (1 << (size - 1)));
    }
}