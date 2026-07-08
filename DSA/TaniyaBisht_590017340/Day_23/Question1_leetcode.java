
class Solution {
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);
        int ch = 0;
        int co = 0;
        while(co<s.length && ch<g.length){
            if(s[co] >= g[ch]){
                ch++;
            }
            co++;
        }
        return ch;
    }
}