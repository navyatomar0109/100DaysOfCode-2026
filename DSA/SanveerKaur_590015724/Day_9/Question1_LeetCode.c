#include <string.h>

int lengthOfLastWord(char* s) {
    int len = strlen(s);
    int count = 0;

    int i = len - 1;

    // Skip trailing spaces
    while (i >= 0 && s[i] == ' ') {
        i--;
    }

    // Count characters of last word
    while (i >= 0 && s[i] != ' ') {
        count++;
        i--;
    }

    return count;
}