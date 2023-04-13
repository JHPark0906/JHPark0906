#include <stdio.h>

typedef struct point {
    int x, y;
} point;

point getFourthPoint(point a, point b, point c);

int main(void) {
    point points[4] = {0};
    for (int i = 0; i < 3; i++)
        scanf("%d %d", &points[i].x, &points[i].y);
    points[3] = getFourthPoint(points[0], points[1], points[2]);
    printf("%d %d", points[3].x, points[3].y);
    return 0;
}

point getFourthPoint(point a, point b, point c) {
    point d;
    d.x = a.x == b.x ? c.x : b.x == c.x ? a.x : b.x;
    d.y = a.y == b.y ? c.y : b.y == c.y ? a.y : b.y;
    return d;
}