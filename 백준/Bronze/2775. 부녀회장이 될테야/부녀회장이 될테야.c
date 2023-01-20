#include <stdio.h>

int family(int floor, int num);

int main(void) {
    int input;
    scanf("%d", &input);
    int floor, num;
    for (int i = 0; i < input; i++) {
        scanf("%d%d", &floor, &num);
        printf("%d\n", family(floor, num));
    }
    return 0;
}

int family(int floor, int num) {
    int result = 0;
    if (floor == 0) return num;
    for (int i = 1; i <= num; i++) {
        result += family(floor - 1, i);
    }
    return result;
}