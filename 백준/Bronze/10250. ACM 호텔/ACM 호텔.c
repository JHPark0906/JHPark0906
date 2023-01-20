#include <stdio.h>

int main(void) {
    int input;
    scanf("%d", &input);
    int height, width, number;
    int floor, room;
    for (int i = 0; i < input; i++) {
        scanf("%d%d%d", &height, &width, &number);
        floor = number % height;
        room = number / height + 1;
        if (!floor) {
            room--;
            floor = height;
        }
        printf("%d\n", floor * 100 + room);
    }
    return 0;
}