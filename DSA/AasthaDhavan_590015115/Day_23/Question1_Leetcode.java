class Solution {
    public int findContentChildren(int[] g, int[] s) {
        int child=0;
        int cookie=0;
        Arrays.sort(g);
        Arrays.sort(s);
        while(cookie<s.length && child<g.length){
            if(s[cookie]>=g[child]){
                child++;
            }
            cookie++;
        }
        return child;

    }
}