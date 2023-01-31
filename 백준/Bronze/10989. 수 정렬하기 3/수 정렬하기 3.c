#include <stdio.h>

int main(void) {
    int len;
    scanf("%d", &len);
    int countingSort[10000] = {0};
    int tmp;
    for (int i = 0; i < len; i++) {
        scanf("%d", &tmp);
        countingSort[tmp - 1]++;
    }
    int cnt = 0;
    for (int i = 0; i < 10000; i++) {
        if (cnt == len) break;
        while (countingSort[i]) {
            printf("%d\n", i + 1);
            cnt++;
            countingSort[i]--;
        }
    }
    return 0;
}