#include <stdio.h>

int main(void) {
    int input[8];
    for (int i = 0; i < 8; i++) {
        scanf("%d", &input[i]);
    }
    int result = 0;
    result = input[0] < input[1] ? 1 : 2;
    for (int i = 0; i < 7; i++) {
        if (result == 1 && input[i] > input[i + 1] || result == 2 && input[i] < input[i + 1]) {
            result = 0;
            break;
        }
    }
    switch (result) {
        case 1:
            printf("ascending");
            break;
        case 2:
            printf("descending");
            break;
        default:
            printf("mixed");
    }
    return 0;
}