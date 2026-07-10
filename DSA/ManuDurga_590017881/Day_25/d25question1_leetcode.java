package Day_25;

import java.util.*;

public class d25question1_leetcode {
    
    public static class Solution {
    public int triangleNumber(int[] nums) {
        Arrays.sort(nums);
        int count=0;
        for(int i=nums.length-1;i>=2;i--)
        {
            int left=0;
            int right=i-1;
            
            while(left<right)
            {
                if((nums[right]+nums[left])<=nums[i])
                  left++;
                else{
                  count=count+(right-left);
                  right--;
                }        
            
            }
        }
        return count;
    }
}


    public static void main(String[] args) {
       Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();          // size of the input array
        int[] Arr = new int[n];
        for (int i = 0; i < n; i++) {
            Arr[i] = sc.nextInt();     // elements of the array
        }

        
        Solution sol = new Solution();
        int ans = sol.triangleNumber(Arr);
        System.out.print(ans);
        sc.close();
    }
}
