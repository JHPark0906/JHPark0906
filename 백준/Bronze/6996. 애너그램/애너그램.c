#include <stdio.h>
#include <string.h>

#define MAX 101

int isAnagram(char str1[], char str2[]);

int main(void) {
    int iteration, len1, len2;
    char str1[MAX], str2[MAX];
    scanf("%d", &iteration);
    for (int i = 0; i < iteration; i++) {
        scanf("%s%s", str1, str2);
        if (isAnagram(str1, str2)) printf("%s & %s are anagrams.\n", str1, str2);
        else printf("%s & %s are NOT anagrams.\n", str1, str2);
    }
    return 0;
}

int isAnagram(char str1[], char str2[]) {
    int alphabet[26] = {0}, len1 = strlen(str1), len2 = strlen(str2);
    if (len1 != len2) return 0;
    for (int i = 0; i < len1; i++) alphabet[str1[i]-'a']++;
    for (int i = 0; i < len2; i++) alphabet[str2[i]-'a']--;
    for (int i = 0; i < 26; i++) if (alphabet[i]) return 0;
    return 1;
}