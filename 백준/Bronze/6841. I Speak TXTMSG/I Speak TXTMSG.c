#include <stdio.h>
#include <string.h>

#define STR_MAX 6

int main(void) {
    char str[STR_MAX];
    while (1) {
        scanf("%s", str);
        if (!strcmp(str, "CU")) printf("see you\n");
        else if (!strcmp(str, ":-)")) printf("I’m happy\n");
        else if (!strcmp(str, ":-(")) printf("I’m unhappy\n");
        else if (!strcmp(str, ";-)")) printf("wink\n");
        else if (!strcmp(str, ":-P")) printf("stick out my tongue\n");
        else if (!strcmp(str, "(~.~)")) printf("sleepy\n");
        else if (!strcmp(str, "TA")) printf("totally awesome\n");
        else if (!strcmp(str, "CCC")) printf("Canadian Computing Competition\n");
        else if (!strcmp(str, "CUZ")) printf("because\n");
        else if (!strcmp(str, "TY")) printf("thank-you\n");
        else if (!strcmp(str, "YW")) printf("\tyou’re welcome\n");
        else if (!strcmp(str, "TTYL")) {
            printf("talk to you later");
            break;
        } else {
            printf("%s\n", str);
        }
    }
    return 0;
}