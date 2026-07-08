#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool backspaceCompare(char *s, char *t) {
    int i = strlen(s) - 1;
    int j = strlen(t) - 1;

    while (i >= 0 || j >= 0) {

        int skip = 0;
        while (i >= 0) {
            if (s[i] == '#') {
                skip++;
                i--;
            } else if (skip > 0) {
                skip--;
                i--;
            } else {
                break;
            }
        }

        skip = 0;
        while (j >= 0) {
            if (t[j] == '#') {
                skip++;
                j--;
            } else if (skip > 0) {
                skip--;
                j--;
            } else {
                break;
            }
        }

        if (i >= 0 && j >= 0) {
            if (s[i] != t[j])
                return false;
        } else if (i >= 0 || j >= 0) {
            return false;
        }

        i--;
        j--;
    }

    return true;
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
