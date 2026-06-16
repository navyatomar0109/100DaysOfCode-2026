//Problem = https://leetcode.com/problems/missing-number/
//Day 1 100 DOC problem Missing Number (Part A)

class Solution {
    public int missingNumber(int[] nums) {
        int n = nums.length;
        int s = (n*(n+1))/2;
        int sum = 0;
        for (int num:nums){
            sum+=num;
            }
        return s-sum;
        }
        
    }
