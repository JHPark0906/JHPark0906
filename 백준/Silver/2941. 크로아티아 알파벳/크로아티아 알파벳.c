#include <stdio.h>
#include <string.h>

int main(void) {
    char input[101];
    scanf("%s", input);
    int len = strlen(input);
    int result = 0;
    for (int i = 0; i < len; i++) {
        result++;
        if (i < len - 2 && input[i] == 'd' && input[i + 1] == 'z' && input[i + 2] == '=') i += 2;
        else if (i < len - 1 && input[i] == 'n' && input[i + 1] == 'j') i++;
        else if (i < len - 1 && input[i] == 'c' && input[i + 1] == '=') i++;
        else if (i < len - 1 && input[i] == 'c' && input[i + 1] == '-') i++;
        else if (i < len - 1 && input[i] == 'd' && input[i + 1] == '-') i++;
        else if (i < len - 1 && input[i] == 's' && input[i + 1] == '=') i++;
        else if (i < len - 1 && input[i] == 'z' && input[i + 1] == '=') i++;
        else if (i < len - 1 && input[i] == 'l' && input[i + 1] == 'j') i++;
    }
    printf("%d", result);
    return 0;
}