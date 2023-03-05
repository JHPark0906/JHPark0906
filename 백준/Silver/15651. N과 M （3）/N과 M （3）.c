#include <stdio.h>

#define MAX 7

void print(int n, int m, int arr[MAX], int selected);

int main(void) {
    int n, m, arr[MAX];
    scanf("%d%d", &n, &m);
    print(n, m, arr, 0);
    return 0;
}

void print(int n, int m, int arr[MAX], int selected) {
    if (selected == m) {
        for (int i = 0; i < m; i++) printf("%d ", arr[i]);
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; i++) {
        arr[selected] = i;
        print(n, m, arr, selected + 1);
    }
}