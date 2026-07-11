class Solution {
    public int compress(char[] c) {
        int i = 0, j = 0;
        while (i < c.length) {
            char x = c[i];
            int k = i;
            while (k < c.length && c[k] == x) k++; c[j++] = x;
            if (k - i > 1) 
            for (char d : String.valueOf(k - i).toCharArray()) c[j++] = d;
            i = k;
        } return j;
    }
}