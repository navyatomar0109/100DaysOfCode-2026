#include <stdio.h>
#include <string.h>

int compress(char chars[], int n) {

    int write = 0;
    int read = 0;

    while (read < n) {

        char current = chars[read];
        int count = 0;

        while (read < n && chars[read] == current) {
            read++;
            count++;
        }

        chars[write++] = current;

        if (count > 1) {
            char temp[10];
            sprintf(temp, "%d", count);

            for (int i = 0; temp[i] != '\0'; i++) {
                chars[write++] = temp[i];
            }
        }
    }

    return write;
}

int main() {

    char chars[] = {'a','a','b','b','c','c','c'};
    int n = sizeof(chars) / sizeof(chars[0]);

    int length = compress(chars, n);

    printf("Compressed Array: ");

    for (int i = 0; i < length; i++) {
        printf("%c ", chars[i]);
    }

    printf("\nLength: %d\n", length);

    return 0;
}