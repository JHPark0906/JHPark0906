#include <stdio.h>
#include <string.h>

#define MAX 257

int main(void) {
    int happy = 0, sad = 0, len, cnt = 0;
    char str[MAX];
    gets(str);
    len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (cnt == 0 && str[i] == ':') cnt = 1;
        else if (cnt == 1 && str[i] == '-') cnt = 2;
        else if (cnt == 2 && str[i] == ')') {
            happy++;
            cnt = 0;
        } else if (cnt == 2 && str[i] == '(') {
            sad++;
            cnt = 0;
        } else cnt = 0;
    }
    printf(happy > sad ? "happy" : happy < sad ? "sad" : !happy ? "none" : "unsure");
    return 0;
}