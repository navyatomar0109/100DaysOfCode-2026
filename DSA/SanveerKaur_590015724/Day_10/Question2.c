#include <stdio.h>

int main() {
    char str[101];
    int freq[26] = {0};
    int count = 0;

    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++) {
        int index = str[i] - 'a';

        if (freq[index] == 0) {
            freq[index] = 1;
            count++;
        }
    }

    if (count % 2 == 0)
        printf("CHAT WITH HER!");
    else
        printf("IGNORE HIM!");

    return 0;
}