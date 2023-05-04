#include <stdio.h>

#define MAX 16

int c[MAX][MAX];

void fill_combination_array(int num);
int get_count(int start_x, int start_y, int end_x, int end_y);
int combination(int n, int r);

int main(void) {
    int y, x, k, k_x, k_y;
    scanf("%d %d %d", &y, &x, &k);
    fill_combination_array(y + x);
    if (k) {
        k--;
        k_x = k % x;
        k_y = k / x;
        printf("%d", get_count(0, 0, k_x, k_y) * get_count(k_x, k_y, x - 1, y - 1));
    } else {
        printf("%d", get_count(0, 0, x - 1, y - 1));
    }

    return 0;
}

void fill_combination_array(int num) {
    c[0][0] = 1; c[1][0] = 1; c[1][1] = 1;
    for (int i = 2; i <= num; i++) {
        for (int j = 0; j < i; j++) {
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
        c[i][i] = 1;
    }
}

int get_count(int start_x, int start_y, int end_x, int end_y) {
    return combination(end_x - start_x + end_y - start_y, end_x - start_x);
}

int combination(int n, int r) {
    return c[n][r];
}