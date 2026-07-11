package Day_26;

import java.util.*;

public class d26question2_technical {
    
    public static class Solution {
    public int tripleSumCheck(int[] nums) {
        Arrays.sort(nums);
        int count=0;
        for(int i=nums.length-1;i>=2;i--)
        {
            int left=0;
            int right=i-1;
            
            while(left<right)
            {
                if((nums[right]+nums[left])<nums[i])
                  left++;
                else if((nums[right]+nums[left])==nums[i]){
                    count=count+1;
                    left++;

                }
                else{
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
        int ans = sol.tripleSumCheck(Arr);
        System.out.print(ans>0);
        sc.close();
    }
}
