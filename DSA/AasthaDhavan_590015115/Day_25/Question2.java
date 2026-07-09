class Question2{
    public static int[] pairsum(int [] nums,int target){
        int n=nums.length;
        int l=0;
        int r=n-1;
        while(l<r){
            int sum=nums[l]+nums[r];
            if(sum==target){
                return true;
            }
            else if(sum<target){
                l++;
            }
            else{
                r--;
            }
        }
        return false;
    }

}