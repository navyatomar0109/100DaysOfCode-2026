package DSA.VridhiJain_590014870.Day_1;
class Solution {
    public int SumArray(int[] nums) {
        int sum = 0;
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
        }
        return sum;
    }
}