#include <stdio.h>
#include <stdbool.h>

void print_star(int size);
bool is_outside_of_triangle(int size, int i, int j);
bool is_reversed_triangle(int size, int i, int j);
bool is_star(int size, int i, int j);

int main(void) {
    int size;
    scanf("%d", &size);
    print_star(size);
    return 0;
}

void print_star(int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < 2 * size - 1; j++) {
            if (is_star(size, i, j))
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

bool is_outside_of_triangle(int size, int i, int j) {
    if (i + j < size - 1 || i - j < 1 - size)
        return true;
    return false;
}

bool is_reversed_triangle(int size, int i, int j) {
    if (i > size / 2 - 1 && !is_outside_of_triangle(size / 2, size - 1 - i, j - size / 2))
        return true;
    return false;
}

bool is_star(int size, int i, int j) {
    if (size == 3) {
        if ((i == 0 && j == 2) || (i == 1 && (j == 1 || j == 3)) || (i == 2))
            return true;
        else
            return false;
    } else {
        int sub_size = size / 2, sub_i, sub_j;
        sub_i = i % sub_size;
        if (i < sub_size) {
            sub_j = j - sub_size;
        } else {
            if (j < size - 1)
                sub_j = j;
            else
                sub_j = j - size;
        }
        if (is_outside_of_triangle(size, i, j))
            return false;
        if (is_reversed_triangle(size, i, j))
            return false;
        return is_star(sub_size, sub_i, sub_j);
    }
}