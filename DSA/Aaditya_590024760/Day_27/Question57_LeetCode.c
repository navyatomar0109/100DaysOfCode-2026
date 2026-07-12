int compress(char* chars, int charsSize) {
    int i = 0, j = 0;

    while (i < charsSize) {
        char ch = chars[i];
        int count = 0;

        while (i < charsSize && chars[i] == ch) {
            i++;
            count++;
        }

        chars[j++] = ch;

        if (count > 1) {
            char temp[10];
            int len = sprintf(temp, "%d", count);
            for (int k = 0; k < len; k++)
                chars[j++] = temp[k];
        }
    }

    return j;
}
