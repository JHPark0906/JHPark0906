#include <stdio.h>
#include <stdbool.h>

#define MAX 15

void nQueen(int selected[MAX], bool visited[MAX], int n, int depth, int *result);
bool selectable(int selected[MAX], int x, int y);

int main(void) {
    int n, result = 0, selected[MAX];
    bool visited[MAX] = {false};
    scanf("%d", &n);
    nQueen(selected, visited, n, 0, &result);
    printf("%d", result);
    return 0;
}

void nQueen(int selected[MAX], bool visited[MAX], int n, int depth, int *result) {
    if (depth >= n) {
        (*result)++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i] && selectable(selected, i, depth)) {
            selected[depth] = i;
            visited[i] = true;
            nQueen(selected, visited, n, depth + 1, result);
            visited[i] = false;
        }
    }
}

bool selectable(int selected[MAX], int x, int y) {
    if (!y) return true;
    for (int i = 1; i <= y; i++) {
        if ((selected[y - i] == x + i) || (selected[y - i] == x - i) || (selected[y - i] == x)) return false;
    }
    return true;
}