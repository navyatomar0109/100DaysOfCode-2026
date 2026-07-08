package Day_23;

import java.util.*;

public class d23question1_leetcode {
    
    public static class Solution {
    public static int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);  
        int satisfiedChildren =0;
        int slen=s.length-1;
        for(int i =g.length-1; i>=0;i--){if(slen>-1){if(g[i]<=s[slen]){satisfiedChildren++;slen--;}}}
        return satisfiedChildren;
    }
}

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Size of Array G: ");
        int n = sc.nextInt();
        int[] g = new int[n];
        System.out.print("Enter elements of Array\n");
        for (int i = 0; i < n; i++) {
            g[i] = sc.nextInt();
        }
        System.out.print("Enter Size of Array S: ");
        n = sc.nextInt();          
        int[] j = new int[n];
        System.out.print("Enter elements of Array\n");
        for (int i = 0; i < n; i++) {
            j[i] = sc.nextInt();
        }
        Solution sol = new Solution();
        int ans = sol.findContentChildren(g,j);
        System.out.print(ans);
        sc.close();
    }
}
