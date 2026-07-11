class Solution {
    public int compress(char[] chars) {

        int index = 0;
        int i = 0;

        while (i < chars.length) {

            char current = chars[i];
            int count = 0;

            while (i < chars.length && chars[i] == current) {
                i++;
                count++;
            }

            chars[index++] = current;

            if (count > 1) {
                char[] num = String.valueOf(count).toCharArray();

                for (char c : num) {
                    chars[index++] = c;
                }
            }
        }

        return index;
    }
}
