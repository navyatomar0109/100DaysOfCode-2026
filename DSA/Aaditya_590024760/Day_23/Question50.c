#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void processString(char* s, char* result) {
    int j = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '#') {
            if (j > 0) j--;
        } else {
            result[j++] = s[i];
        }
    }
    result[j] = '\0';
}

bool backspaceCompare(char* s, char* t) {
    char res1[200], res2[200];

    processString(s, res1);
    processString(t, res2);

    return strcmp(res1, res2) == 0;
}

int main() {
    char s[200], t[200];

    printf("Enter string 1: ");
    scanf("%s", s);
    printf("Enter string 2: ");
    scanf("%s", t);

    if (backspaceCompare(s, t))
        printf("Result: true (strings are equal)");
    else
        printf("Result: false (strings are not equal)");

    return 0;
}
