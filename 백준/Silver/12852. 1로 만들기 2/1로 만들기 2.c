#include <stdio.h>
#include <limits.h>

#define MAX 1000001

typedef struct pair {
    int a, b;
} pair;

pair arr[MAX];

int get_minimum(int a, int b, int c);

int main(void) {
    int num, a, b, c;
    arr[2].a = 1; arr[2].b = 1;
    arr[3].a = 1; arr[3].b = 1;
    scanf("%d", &num);
    for (int i = 4; i <= num; i++) {
        if (i % 3 == 0)
            a = arr[i / 3].a + 1;
        else
            a = INT_MAX;
        if (i % 2 == 0)
            b = arr[i / 2].a + 1;
        else
            b = INT_MAX;
        c = arr[i - 1].a + 1;
        switch(get_minimum(a, b, c)) {
            case 0:
                arr[i].a = a;
                arr[i].b = i / 3;
                break;
            case 1:
                arr[i].a = b;
                arr[i].b = i / 2;
                break;
            case 2:
                arr[i].a = c;
                arr[i].b = i - 1;
        }
    }
    printf("%d\n%d ", arr[num].a, num);
    while (1) {
        if (num <= 1)
            break;
        printf("%d ", arr[num].b);
        num = arr[num].b;
    }
    return 0;
}

int get_minimum(int a, int b, int c) {
    if (a <= b && a <= c)
        return 0;
    if (b <= a && b <= c)
        return 1;
    if (c <= a && c <= b)
        return 2;
    return -1;
}