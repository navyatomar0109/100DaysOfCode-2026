#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void processString(char* input, char* result) {
    int idx = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '#') {
            if (idx > 0) {
                idx--;
            }
        } else {
            result[idx++] = input[i];
        }
    }
    result[idx] = '\0';
}

bool backspaceCompare(char* s, char* t) {
    char processedS[1000];
    char processedT[1000];

    processString(s, processedS);
    processString(t, processedT);

    return strcmp(processedS, processedT) == 0;
}

int main() {
    char s[1000], t[1000];

    scanf("%s %s", s, t);

    if (backspaceCompare(s, t)) {
        printf("true\n");
    } else {
        printf("false\n");
    }

    return 0;
}