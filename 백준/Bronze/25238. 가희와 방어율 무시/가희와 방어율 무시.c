#include <stdio.h>
#include <stdbool.h>

bool bangmuIsJabOp(int bangeryul, int bangmu);

int main(void) {
    int bangeryul, bangmu;
    scanf("%d %d", &bangeryul, &bangmu);
    printf("%d", bangmuIsJabOp(bangeryul, bangmu) ? 1 : 0);
    return 0;
}

bool bangmuIsJabOp(int bangeryul, int bangmu) {
    if (bangeryul * (100 - bangmu) < 10000)
        return true;
    return false;
}