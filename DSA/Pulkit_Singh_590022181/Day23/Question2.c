#include <stdio.h>
#include <string.h>

void process(char str[], char result[]) {
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++) {

        if (str[i] == '#') {
            if (j > 0)
                j--;
        }
        else {
            result[j++] = str[i];
        }
    }

    result[j] = '\0';
}

int backspaceCompare(char s[], char t[]) {

    char res1[1000], res2[1000];

    process(s, res1);
    process(t, res2);

    return strcmp(res1, res2) == 0;
}

int main() {

    char s[] = "ab#c";
    char t[] = "ad#c";

    if (backspaceCompare(s, t))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}