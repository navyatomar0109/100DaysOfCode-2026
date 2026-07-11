package Day_27;

class Solution {
    public int compress(char[] chars) {
        int read=0;
        int write=0;
        while (read <chars.length){
            char current = chars[read];
            int count = 0;
            while (read < chars.length && chars[read] == current){
                count ++;
                read ++;
            }
            chars[write] = current;
            write++;
            if (count > 1) {
                String s = String.valueOf(count);
                for (int i = 0; i < s.length(); i++) {
                    chars[write] = s.charAt(i);
                    write++;
}
        }
    } 
    return write;
}
}
