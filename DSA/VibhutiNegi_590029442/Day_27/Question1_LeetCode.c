int compress(char* chars, int charsSize) {
    int i = 0;
    int index = 0;
    while (i < charsSize)
    {
        char current = chars[i];
        int count = 0;
        while (i < charsSize && chars[i] == current)
        {
            count++;
            i++;
        }
        chars[index++] = current;
        if (count > 1)
        {
            char temp[10];
            int len = sprintf(temp, "%d", count);
            for (int j = 0; j < len; j++)
            {
                chars[index++] = temp[j];
            }
        }
    }
    return index;
}