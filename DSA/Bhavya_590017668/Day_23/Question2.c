#include <stdbool.h>
#include <string.h>

bool backspaceCompare(char *s, char *t) {

    int i, j;
    int k1 = 0, k2 = 0;

    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == '#') {
            if (k1 > 0)
                k1--;
        } else {
            s[k1++] = s[i];
        }
    }
    s[k1] = '\0';

    for (j = 0; t[j] != '\0'; j++) {
        if (t[j] == '#') {
            if (k2 > 0)
                k2--;
        } else {
            t[k2++] = t[j];
        }
    }
    t[k2] = '\0';

    return strcmp(s, t) == 0;
}