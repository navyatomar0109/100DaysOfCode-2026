
class Solution {
    public int missingNumber(int[] nums) {
        int n = nums.length;
        int sumbefore = 0;
        for (int i=0; i<n; i++){
            sumbefore += nums[i];
        }
        int sumafter = (n * (n+1)) / 2;
        int missingno = sumafter - sumbefore;
        return missingno;
    }
}