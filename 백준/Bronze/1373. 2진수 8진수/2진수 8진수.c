#include <stdio.h>
#include <string.h>

char binToOct(char bin[]);

int main(void) {
    char bin[1000001], oct[333335];
    scanf("%s", bin);
    int len = strlen(bin), remainder = (len % 3 ? len % 3 : 3);
    while (bin[0] == '0') {
        memmove(&bin, &bin[1], len - 1);
        bin[len - 1] = '\0';
        len--;
    }
    for (int i = 0; i < len / 3 + (remainder != 3 ? 1 : 0); i++) {
        char part[3] = "000";
        if (!i) {
            switch (remainder) {
                case 3:
                    part[0] = bin[0];
                    part[1] = bin[1];
                    part[2] = bin[2];
                    break;
                case 2:
                    part[1] = bin[0];
                    part[2] = bin[1];
                    break;
                case 1:
                    part[2] = bin[0];
                    break;
            }
        } else {
            part[0] = bin[3 * i + remainder - 3];
            part[1] = bin[3 * i + remainder - 2];
            part[2] = bin[3 * i + remainder - 1];
        }
        oct[i] = binToOct(part);
    }
    printf("%s", oct);
    return 0;
}

char binToOct(char bin[]) {
    int result = 0;
    if (bin[0] == '1') result += 4;
    if (bin[1] == '1') result += 2;
    if (bin[2] == '1') result += 1;
    return '0' + result;
}