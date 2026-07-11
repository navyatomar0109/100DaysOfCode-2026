class Solution {
    public int compress(char[] chars) {
        int index = 0;
        int i = 0;
        while (i < chars.length) {
            char current = chars[i];
            int count = 0;
            while (i < chars.length && chars[i] == current) {
                count++;
                i++;
            }
            chars[index++] = current;
            if (count > 1) {
                String s = Integer.toString(count);
                for (int j = 0; j < s.length(); j++) {
                    chars[index++] = s.charAt(j);
                }
            }
        }
        return index;
    }
}