#include <stdio.h>

#define ARR_MAX 1001

int maze[ARR_MAX][ARR_MAX];
int candyMax[ARR_MAX][ARR_MAX];

int max(int a, int b, int c);

int main(void) {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &maze[i][j]);

    candyMax[n - 1][m - 1] = maze[n - 1][m - 1];
    for (int j = m - 2; j >= 0; j--)
        candyMax[n - 1][j] = maze[n - 1][j] + candyMax[n - 1][j + 1];
    for (int i = n - 2; i >= 0; i--)
        candyMax[i][m - 1] = maze[i][m - 1] + candyMax[i + 1][m - 1];

    for (int i = n - 2; i >= 0; i--) {
        for (int j = m - 2; j >= 0; j--) {
            candyMax[i][j] = maze[i][j] + max(candyMax[i + 1][j], candyMax[i + 1][j + 1], candyMax[i][j + 1]);
        }
    }

    printf("%d", candyMax[0][0]);
    return 0;
}

int max(int a, int b, int c) {
    return a > b ? b > c ? a : a > c ? a : c : b > c ? b : c;
}