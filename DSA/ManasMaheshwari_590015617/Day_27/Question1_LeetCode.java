class Solution {
    public int compress(char[] chars) {
        int index = 0;
        int i = 0;
        
        while (i < chars.length) {
            int j = i;
            while (j < chars.length && chars[j] == chars[i]) {
                j++;
            }
            
            chars[index++] = chars[i];
            int count = j - i;
            
            if (count > 1) {
                String countStr = String.valueOf(count);
                for (char c : countStr.toCharArray()) {
                    chars[index++] = c;
                }
            }
            
            i = j;
        }
        
        return index;
    }
}
