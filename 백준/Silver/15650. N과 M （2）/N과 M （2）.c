#include <stdio.h>
#include <stdbool.h>

#define MAX 9

void printArr(int selected[MAX], bool visited[MAX], int n, int m, int depth, int min);

int main(void) {
    int n, m, selected[MAX];
    bool visited[MAX] = {false};
    scanf("%d%d", &n, &m);
    printArr(selected, visited, n, m, 0, 1);
    return 0;
}

void printArr(int selected[MAX], bool visited[MAX], int n, int m, int depth, int min) {
    if (depth == m) {
        for (int i = 0; i < m; i++) {
            printf("%d ", selected[i]);
        }
        printf("\n");
        return;
    }
    for (int i = min; i <= n; i++) {
        if (!visited[i]) {
            selected[depth] = i;
            visited[i] = true;
            printArr(selected, visited, n, m, depth + 1, i);
            visited[i] = false;
        }
    }
}