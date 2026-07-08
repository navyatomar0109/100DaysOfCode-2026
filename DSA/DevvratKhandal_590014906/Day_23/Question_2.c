#include <stdio.h>
#include <string.h>

void process(char str[], char result[])
{
    int top = -1;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != '#')
        {
            result[++top] = str[i];
        }
        else
        {
            if (top >= 0)
                top--;
        }
    }

    result[top + 1] = '\0';
}

int main()
{
    char s[1000], t[1000];
    char res1[1000], res2[1000];

    printf("Enter first string: ");
    scanf("%s", s);

    printf("Enter second string: ");
    scanf("%s", t);

    process(s, res1);
    process(t, res2);

    if (strcmp(res1, res2) == 0)
        printf("true\n");
    else
        printf("false\n");

    return 0;
}