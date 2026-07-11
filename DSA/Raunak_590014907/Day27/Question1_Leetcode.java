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

                String str = Integer.toString(count);

                for (char ch : str.toCharArray()) {
                    chars[index++] = ch;
                }
            }
        }

        return index;
    }
}