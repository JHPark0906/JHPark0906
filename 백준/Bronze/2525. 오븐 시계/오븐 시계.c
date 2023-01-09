#include <stdio.h>

int main(void) {
    int hour;
    int minute;
    int cooking_time;
    scanf("%d %d", &hour, &minute);
    scanf("%d", &cooking_time);
    hour += cooking_time / 60 + (cooking_time % 60 + minute) / 60;
    hour %= 24;
    minute += cooking_time;
    minute %= 60;
    printf("%d %d", hour, minute);
    return 0;
}