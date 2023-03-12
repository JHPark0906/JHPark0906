#include <stdio.h>
#include <stdbool.h>

#define MAX 13

void printLotto(int arr[MAX], int selected[MAX], bool visited[MAX], int size, int depth, int min);

int main(void) {
    int arr[MAX], size, selected[MAX];
    bool visited[MAX] = {false};
    while(1) {
        scanf("%d", &size);
        if (!size) break;
        for (int i = 0; i < size; i++) scanf("%d", &arr[i]);
        printLotto(arr, selected, visited, size, 0, 1);
        printf("\n");
    }
    return 0;
}

void printLotto(int arr[MAX], int selected[MAX], bool visited[MAX], int size, int depth, int min) {
    if (depth == 6) {
        for (int i = 0; i < 6; i++) printf("%d ", selected[i]);
        printf("\n");
        return;
    }
    for (int i = min; i <= size; i++) {
        if (!visited[i]) {
            selected[depth] = arr[i - 1];
            visited[i] = true;
            printLotto(arr, selected, visited, size, depth + 1, i);
            visited[i] = false;
        }
    }
}