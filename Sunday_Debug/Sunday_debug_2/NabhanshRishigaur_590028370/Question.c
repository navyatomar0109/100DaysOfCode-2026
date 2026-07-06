#include <stdio.h>
#include <ctype.h>

int main() {
    char *names[] = {"Harry", "Ron", "Hermione"};
    char password[] = "nurses run";
    char spell[] = "expelliarmus";

    char *valid[] = {"nox", "expelliarmus", "alohomora"};

    int ok = 0;

    for (int i = 0; i < 3; i++) {
        char *a = spell;
        char *b = valid[i];

        while (*a && *b && *a == *b) {
            a++;
            b++;
        }

        if (*a == '\0' && *b == '\0') {
            ok = 1;
            break;
        }
    }

    if (!ok) {
        printf("Invalid spell!\n");
        return 0;
    }

    printf("Spell accepted!\n");

    char temp[100];
    int len = 0;

    for (char *p = password; *p; p++) {
        if (*p != ' ')
            temp[len++] = tolower(*p);
    }

    int left = 0, right = len - 1;
    while (left < right) {
        if (temp[left] != temp[right]) {
            printf("Wrong password!\n");
            return 0;
        }
        left++;
        right--;
    }

    printf("Scroll unlocked!\n");

    printf("Initials: [");
    for (int i = 0; i < 3; i++) {
        printf("'%c'", toupper(names[i][0]));
        if (i < 2)
            printf(", ");
    }
    printf("]\n");

    printf("Concealed: [");
    for (int i = 0; i < 3; i++) {
        printf("'");
        for (char *p = names[i]; *p; p++)
            putchar('*');
        printf("'");
        if (i < 2)
            printf(", ");
    }
    printf("]\n");

    return 0;
}
