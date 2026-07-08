class Solution {
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);
        int child = 0, c = 0;

        while (child < g.length && c < s.length) 
        {
            if (s[c] >= g[child]) 
                child++;
            c++;
        }
        return child;
    }
}
