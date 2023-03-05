#include <stdio.h>
#include <string.h>

int getCurrentArea(int h);
void addTime(int *h, int *m, int addMin);

int main(void) {
    int h, m, s, t, clock[6], clear[6] = {0}, iteration, result = 0;
    char startTime[6], action[6];
    scanf("%d:%d", &h, &m);
    for (int i = 0; i < 6; i++) scanf("%d", &clock[i]);
    scanf("%d", &iteration);
    for (int i = 0; i < iteration; i++) {
        scanf("%d.%d %s", &s, &t, action);
        if (s >= 60) break;
        if (!strcmp(action, "^")) clear[getCurrentArea(h)] = 1;
        else if (!strcmp(action, "10MIN")) addTime(&h, &m, 10);
        else if (!strcmp(action, "30MIN")) addTime(&h, &m, 30);
        else if (!strcmp(action, "50MIN")) addTime(&h, &m, 50);
        else if (!strcmp(action, "2HOUR")) addTime(&h, &m, 120);
        else if (!strcmp(action, "4HOUR")) addTime(&h, &m, 240);
        else if (!strcmp(action, "9HOUR")) addTime(&h, &m, 540);
    }
    for (int i = 0; i < 6; i++) if (!clear[i]) result += clock[i];
    printf("%d", result > 100 ? 100 : result);
    return 0;
}

int getCurrentArea(int h) {
    return h / 2;
}

void addTime(int *h, int *m, int addMin) {
    *m += addMin;
    *h += (*m) / 60;
    *h %= 12;
    *m %= 60;
}