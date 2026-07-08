#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool backspaceCompare(char* s1, char* s2) {
    int i = strlen(s1) - 1;
    int j = strlen(s2) - 1;
    while (i >= 0 || j >= 0) {
        int skip1 = 0;
        while (i >= 0) {
            if (s1[i] == '#') {
                skip1++;
                i--;
            } else if (skip1 > 0) {
                skip1--;
                i--;
            } else {
                break;
            }
        
        int skip2 = 0;
        while (j >= 0) {
            if (s2[j] == '#') {
                skip2++;
                j--;
            } else if (skip2 > 0) {
                skip2--;
                j--;
            }else {
                break;
            }
        }
        if (i >= 0 && j >= 0) {
            if (s1[i] != s2[j])
                return false;
        }
        else if (i >= 0 || j >= 0) {
            return false;
        }
        i--;
        j--;
    }

    return true;
}
}
int main() {
    char s1[100];
    char s2[100];
    printf("Enter first string: ");
    scanf("%s", s1);
    printf("Enter second string: ");
    scanf("%s", s2);
    if (backspaceCompare(s1, s2))
        printf("true");
    else
        printf("false");

    return 0;
}