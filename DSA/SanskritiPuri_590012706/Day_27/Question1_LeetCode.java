class Solution {
    public int compress(char[] chars) {
         int write = 0;
        int read = 0;

        while (read < chars.length) {
            char current = chars[read];
            int count = 0;

            while (read < chars.length && chars[read] == current) {
                read++;
                count++;
            }

            chars[write++] = current;

            if (count > 1) {
                String str = String.valueOf(count);
                for (char c : str.toCharArray()) {
                    chars[write++] = c;
                }
            }
        }

        return write;
        
    }
}
