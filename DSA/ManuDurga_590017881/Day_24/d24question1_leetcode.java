package Day_24;

import java.util.*;

public class d24question1_leetcode {
    
    public static class Solution {
    public boolean isHappy(int n) {
        int sum = 0;
        while (n > 0) {
            int rem = n % 10;
            sum += rem * rem;
            n /= 10;
        }
        if (sum == 1) return true;
        if (sum == 4) return false; // 4 is the start of the unhappy cycle
        return isHappy(sum);
    }
}


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter: ");
        int n = sc.nextInt();
        
        Solution sol = new Solution();
        boolean ans = sol.isHappy(n);
        System.out.print(ans);
        sc.close();
    }
}
