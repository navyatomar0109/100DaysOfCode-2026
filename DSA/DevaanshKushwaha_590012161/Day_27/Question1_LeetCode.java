class Solution {
    public int compress(char[] chars) {
        int write = 0;
        int read = 0;
        int n = chars.length;

        while (read < n) {
            char currentChar = chars[read];
            int count = 0;

            // Count the length of this group
            while (read < n && chars[read] == currentChar) {
                read++;
                count++;
            }

            // Write the character
            chars[write++] = currentChar;

            // Write the count (if > 1), digit by digit
            if (count > 1) {
                String countStr = String.valueOf(count);
                for (char digit : countStr.toCharArray()) {
                    chars[write++] = digit;
                }
            }
        }

        return write;
    }
}
