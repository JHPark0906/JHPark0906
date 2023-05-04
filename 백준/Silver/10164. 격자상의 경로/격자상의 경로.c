#include <stdio.h>

#define MAX 16

int c[MAX][MAX];

void fill_combination_array(int num);
int get_count(int start_x, int start_y, int end_x, int end_y);
int combination(int n, int r);

int main(void) {
    int n, m, k, k_x, k_y;
    scanf("%d %d %d", &n, &m, &k);
    fill_combination_array(n + m);
    if (k) {
        k_x = k % m - 1;
        k_y = k / m - (k_x ? 0 : 1);
        printf("%d", get_count(0, 0, k_x, k_y) * get_count(k_x, k_y, m - 1, n - 1));
    } else {
        printf("%d", get_count(0, 0, m - 1, n - 1));
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