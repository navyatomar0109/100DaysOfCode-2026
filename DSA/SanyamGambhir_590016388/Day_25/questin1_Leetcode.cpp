class Solution {
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