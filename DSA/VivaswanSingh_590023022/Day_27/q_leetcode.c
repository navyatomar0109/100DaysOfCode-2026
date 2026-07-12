int compress(char* chars, int charsSize)
{
    int read = 0;
    int write = 0;

    while (read < charsSize)
    {
        char current = chars[read];
        int count = 0;

        while (read < charsSize && chars[read] == current)
        {
            read++;
            count++;
        }

        chars[write++] = current;

        if (count > 1)
        {
            int start = write;

            while (count > 0)
            {
                chars[write++] = (count % 10) + '0';
                count /= 10;
            }

            int end = write - 1;

            while (start < end)
            {
                char temp = chars[start];
                chars[start] = chars[end];
                chars[end] = temp;

                start++;
                end--;
            }
        }
    }

    return write;
}