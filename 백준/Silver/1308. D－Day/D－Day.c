#include <stdio.h>

int dayCounter(int y, int m, int d);
int isLeapYear(int y);

int main(void) {
    int y1, m1, d1, y2, m2, d2;
    scanf("%d%d%d%d%d%d", &y1, &m1, &d1, &y2, &m2, &d2);

    int days1 = dayCounter(y1, m1, d1);
    int days2 = dayCounter(y2, m2, d2);
    int dayLimit = dayCounter(y1 + 1000, m1, d1);

    if (dayLimit <= days2) printf("gg");
    else printf("D-%d", days2 - days1);
    return 0;
}

int dayCounter(int y, int m, int d) {
    int result = 0;
    int daysOfMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    for (int i = 0; i < y; i++) result += isLeapYear(i) ? 366 : 365;
    if (isLeapYear(y)) daysOfMonth[1]++;
    for (int i = 0; i < m - 1; i++) result += daysOfMonth[i];
    result += d;

    return result;
}

int isLeapYear(int y) {
    return !(y % 4) ? !(y % 100) && (y % 400) ? 0 : 1 : 0;
}