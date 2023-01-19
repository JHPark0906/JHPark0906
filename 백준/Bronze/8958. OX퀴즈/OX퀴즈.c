#include <stdio.h>
#include <string.h>

int main(void) {
    int input;
    scanf("%d", &input);
    char answer[81];
    int len;
    int point, score;
    for (int i = 0; i < input; i++) {
        score = 0;
        point = 1;
        scanf("%s", answer);
        len = strlen(answer);
        for (int j = 0; j < len; j++) {
            if (answer[j] == 'O') {
                score += point++;
            } else point = 1;
        }
        printf("%d\n", score);
    }
    return 0;
}