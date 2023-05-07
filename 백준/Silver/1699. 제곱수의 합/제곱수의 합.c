#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX 100001
#define SQUARE_MAX 318

int terms[MAX];
int square[SQUARE_MAX];

void getMinimum(int num);
bool isSquareNumber(int num);

int main(void) {
    int num;
    scanf("%d", &num);
    for (int i = 0; i < SQUARE_MAX; i++)
        square[i] = i * i;
    for (int i = 0; i <= num; i++)
        getMinimum(i);
    printf("%d", terms[num]);
    return 0;
}

void getMinimum(int num) {
    if (isSquareNumber(num))
        terms[num] = 1;
    else {
        int idx = 1, tmp, currentMin = INT_MAX;
        while (square[idx] < num) {
            tmp = 1 + terms[num - square[idx]];
            currentMin = currentMin < tmp ? currentMin : tmp;
            idx++;
        }
        terms[num] = currentMin;
    }
}

bool isSquareNumber(int num) {
    for (int i = 0; i < SQUARE_MAX; i++) {
        if (square[i] == num)
            return true;
    }
    return false;
}