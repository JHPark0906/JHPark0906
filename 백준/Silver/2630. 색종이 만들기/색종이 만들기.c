#include <stdio.h>

void cuttingPaper(int paper[128][128], int left, int top, int right, int bottom, int *white, int *blue);
int isOneColored(int paper[128][128], int left, int top, int right, int bottom);

int main(void) {
    int paper[128][128], size, white = 0, blue = 0;
    scanf("%d", &size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) scanf("%d", &paper[i][j]);
    }
    cuttingPaper(paper, 0, 0, size - 1, size - 1, &white, &blue);
    printf("%d\n%d", white, blue);
    return 0;
}

void cuttingPaper(int paper[128][128], int left, int top, int right, int bottom, int *white, int *blue) {
    if (left == right || top == bottom || isOneColored(paper, left, top, right, bottom)) {
        if (paper[left][top]) (*blue)++;
        else (*white)++;
    } else {
        int x = (left + right) / 2, y = (top + bottom) / 2;
        cuttingPaper(paper, left, top, x, y, white, blue);
        cuttingPaper(paper, x + 1, top, right, y, white, blue);
        cuttingPaper(paper, left, y + 1, x, bottom, white, blue);
        cuttingPaper(paper, x + 1, y + 1, right, bottom, white, blue);
    }
}

int isOneColored(int paper[128][128], int left, int top, int right, int bottom) {
    for (int i = left; i <= right; i++) {
        for (int j = top; j <= bottom; j++) {
            if (paper[i][j] != paper[left][top]) return 0;
        }
    }
    return 1;
}