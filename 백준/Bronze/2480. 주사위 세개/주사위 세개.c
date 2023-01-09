#include <stdio.h>

int main(void) {
    int dice[3];
    int arr[6] = {0};
    int num = 0, reward = 0;
    for (int i = 0; i < 3; i++) {
        scanf("%d", &dice[i]);
        arr[dice[i] - 1]++;
    }
    for (int i = 0; i < 6; i++) {
        if (arr[i] == 3) {
            reward = 10000 + 1000 * (i + 1);
            break;
        } else if (arr[i] == 2) {
            reward = 1000 + 100 * (i + 1);
            break;
        } else if (arr[i] == 1) {
            num = i + 1;
        }
    }
    if (reward == 0) reward += 100 * num;
    printf("%d", reward);
    return 0;
}