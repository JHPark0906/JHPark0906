#include <stdio.h>
#include <string.h>

int groupWord(char arr[]);

int main(void) {
    int input;
    scanf("%d", &input);
    char word[101];
    int result = 0;
    for (int i = 0; i < input; i++) {
        scanf("%s", word);
        if (groupWord(word)) result++;
    }
    printf("%d", result);
    return 0;
}

int groupWord(char arr[]) {
    int len = strlen(arr);
    int alphabet[26] = {0};
    for (int i = 0; i < len; i++) {
        alphabet[arr[i] - 'a']++;
        if (alphabet[arr[i] - 'a'] == 2) {
            if (arr[i] != arr[i - 1]) return 0;
            else alphabet[arr[i] - 'a'] = 1;
        }
    }
    return 1;
}