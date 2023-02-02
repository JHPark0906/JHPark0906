#include <stdio.h>
#include <string.h>

int main() {
    char octal[333335];
    scanf("%s", octal);
    int len = strlen(octal);
    if (len == 1 && octal[0] == '0') {
        printf("0");
        return 0;
    }
    while (len != 1 && octal[0] == '0') {
        for (int i = 0; i < len - 1; i++) octal[i] = octal[i + 1];
        len--;
    }
    switch (octal[0]) {
        case '1':
            printf("1");
            break;
        case '2':
            printf("10");
            break;
        case '3':
            printf("11");
            break;
        case '4':
            printf("100");
            break;
        case '5':
            printf("101");
            break;
        case '6':
            printf("110");
            break;
        case '7':
            printf("111");
            break;
    }
    for (int i = 1; i < len; i++) {
        switch (octal[i]) {
            case '0':
                printf("000");
                break;
            case '1':
                printf("001");
                break;
            case '2':
                printf("010");
                break;
            case '3':
                printf("011");
                break;
            case '4':
                printf("100");
                break;
            case '5':
                printf("101");
                break;
            case '6':
                printf("110");
                break;
            case '7':
                printf("111");
                break;
        }
    }
    return 0;
}