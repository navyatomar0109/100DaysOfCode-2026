class Solution {
    public int compress(char[] chars) {

        int write = 0;
        int i = 0;

        while(i < chars.length) {

            char current = chars[i];
            int count = 0;
            while(i < chars.length && chars[i] == current) {
                count++;
                i++;
            }
            chars[write] = current;
            write++;
            if(count > 1) {

                String str = String.valueOf(count);

                for(char c : str.toCharArray()) {
                    chars[write] = c;
                    write++;
                }
            }
        }

        return write;
    }
}