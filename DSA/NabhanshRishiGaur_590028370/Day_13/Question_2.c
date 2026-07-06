#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SUB 2000
#define MAX_LEN 20

char subs[MAX_SUB][MAX_LEN];
int cnt;

bool exists(char str[]) {
    for (int i = 0; i < cnt; i++) {
        if (strcmp(subs[i], str) == 0)
            return true;
    }
    return false;
}

void generate(char s[], int index, char temp[], int len) {
    if (index == strlen(s)) {
        temp[len] = '\0';

        if (!exists(temp)) {
            strcpy(subs[cnt++], temp);
        }
        return;
    }
    temp[len] = s[index];
    generate(s, index + 1, temp, len + 1);

    generate(s, index + 1, temp, len);
}

int distinctCount(char s[]) {
    cnt = 0;
    char temp[MAX_LEN];
    generate(s, 0, temp, 0);
    return cnt;
}

int main() {
    char s1[MAX_LEN], s2[MAX_LEN];

    printf("Enter first string: ");
    scanf("%s", s1);

    printf("Enter second string: ");
    scanf("%s", s2);

    int c1 = distinctCount(s1);
    int c2 = distinctCount(s2);

    if (c1 >= c2)
        printf("%s\n", s1);
    else
        printf("%s\n", s2);

    return 0;
}
