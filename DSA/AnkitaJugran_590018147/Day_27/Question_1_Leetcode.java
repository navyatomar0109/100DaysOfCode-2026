class Solution {
    public int compress(char[] chars) {
        
        int write = 0;
        int i = 0;

        while( i < chars.length ){

            int count = 0;

            char unique_char = chars[i];

            while( i < chars.length && chars[i] == unique_char ){
                count++;
                i++;
            }

            chars[write++] = unique_char;

            if ( count > 1) {
                String str = Integer.toString(count);

                for (char c : str.toCharArray()) 
                {
                chars[write++] = c;
                }

            }

            
        }
        return write;
    }
}