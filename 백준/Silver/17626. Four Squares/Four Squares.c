#include <stdio.h>

#define MAX 50001

int arr[MAX];

void fillArray(int num);

int main(void) {
    int num;
    scanf("%d", &num);
    for (int i = 1; i * i <= num; i++) {
        arr[i * i] = 1;
    }
    for (int i = 1; i <= num; i++)
        fillArray(i);
    printf("%d", arr[num]);
    return 0;
}

void fillArray(int num) {
    if (arr[num] == 1) return;
    int tmp;
    arr[num] = 4;
    for (int i = num - 1; i >= num / 2; i--) {
        tmp = arr[i] + arr[num - i];
        if (tmp == 2) {
            arr[num] = 2;
            return;
        } else if (tmp < arr[num]) {
            arr[num] = tmp;
        }
    }
}