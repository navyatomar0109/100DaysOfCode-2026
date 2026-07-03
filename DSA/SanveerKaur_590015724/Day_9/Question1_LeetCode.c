int lengthOfLastWord(char *s) {

    int i = 0;

    // Find the length of the string
    while (s[i] != '\0')
        i++;

    i--; // Move to the last character

    // Skip trailing spaces
    while (i >= 0 && s[i] == ' ')
        i--;

    int count = 0;

    // Count characters of the last word
    while (i >= 0 && s[i] != ' ') {
        count++;
        i--;
    }

    return count;
}