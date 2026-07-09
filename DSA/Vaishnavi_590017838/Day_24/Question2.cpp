class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int index = nums.size() - 1;
        vector<int> result(nums.size());
        while(left <= right) {
            if(abs(nums[left]) > abs(nums[right])) {
                result[index] = nums[left] * nums[left];
                left++;
            }
            else {
                result[index] = nums[right] * nums[right];
                right--;
            }
            index--;
        }
        return result;
    }
};
