#include <stdio.h>
#include <string.h>

int main(void) {
    char input[16];
    scanf("%s", input);
    int time[26] = {3, 3, 3,
                    4, 4, 4,
                    5, 5, 5,
                    6, 6, 6,
                    7, 7, 7,
                    8, 8, 8, 8,
                    9, 9, 9,
                    10, 10, 10, 10};
    int result = 0;
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        result += time[input[i] - 'A'];
    }
    printf("%d", result);
    return 0;
}