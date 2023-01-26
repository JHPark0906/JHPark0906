#include <stdio.h>

int main(void) {
    int vacation, totalKorean, totalMath, dailyKorean, dailyMath;
    scanf("%d%d%d%d%d", &vacation, &totalKorean, &totalMath, &dailyKorean, &dailyMath);
    int korean = totalKorean / dailyKorean + (totalKorean % dailyKorean ? 1 : 0);
    int math = totalMath / dailyMath + (totalMath % dailyMath ? 1 : 0);
    int result = korean > math ? vacation - korean : vacation - math;
    printf("%d", result > 0 ? result : 0);
    return 0;
}