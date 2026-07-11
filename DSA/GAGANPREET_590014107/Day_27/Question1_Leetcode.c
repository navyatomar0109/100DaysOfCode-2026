int compress(char* chars, int charsSize) {
    int write = 0;
    int i = 0;

    while (i < charsSize) {
        char current = chars[i];
        int count = 0;

        
        while (i < charsSize && chars[i] == current) {
            count++;
            i++;
        }

        chars[write++] = current;

     
        if (count > 1) {
            char temp[12];
            int len = sprintf(temp, "%d", count);

            for (int j = 0; j < len; j++) {
                chars[write++] = temp[j];
            }
        }
    }

    return write;
}
