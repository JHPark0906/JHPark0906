#include <stdio.h>

#define ARR_MAX 11

int num, arr[ARR_MAX], operator[4], selected[ARR_MAX], used[4] = {0}, min = 1, max = 0;

void check(int depth);
int getResult();

int main(void) {
    scanf("%d", &num);
    for (int i = 0; i < num; i++) scanf("%d", &arr[i]);
    for (int i = 0; i < 4; i++) scanf("%d", &operator[i]);
    check(0);
    printf("%d\n%d", max, min);
    return 0;
}

void check(int depth) {
    if (depth == num - 1) {
        int tmp = getResult();
        if (min > max) {
            min = tmp;
            max = tmp;
        } else {
            if (max < tmp) max = tmp;
            if (tmp < min) min = tmp;
        }
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (used[i] < operator[i]) {
            selected[depth] = i;
            used[i]++;
            check(depth + 1);
            used[i]--;
        }
    }
}

int getResult() {
    int tmp = arr[0];
    for (int i = 0; i < num - 1; i++) {
        switch(selected[i]) {
            case 0:
                tmp += arr[i + 1];
                break;
            case 1:
                tmp -= arr[i + 1];
                break;
            case 2:
                tmp *= arr[i + 1];
                break;
            case 3:
                tmp /= arr[i + 1];
                break;
        }
    }
    return tmp;
}