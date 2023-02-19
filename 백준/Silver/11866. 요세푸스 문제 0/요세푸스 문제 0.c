#include <stdio.h>

int main(void) {
    int arr[1001] = {0}, n, k, idx = 0, cnt = 0, printed = 0;
    scanf("%d%d", &n, &k);
    printf("<");
    while (printed < n) {
        cnt++;
        while (arr[idx]) idx = (idx + 1) % n;
        if (cnt == k) {
            printf("%d", idx + 1);
            cnt = 0;
            arr[idx] = 1;
            printed++;
            if (printed < n) printf(", ");
        }
        idx = (idx + 1) % n;
    }
    printf(">");
    return 0;
}