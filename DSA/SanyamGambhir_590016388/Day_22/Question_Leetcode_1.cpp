class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0; // Points to the next position for a non-zero element
        
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != 0) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
    }
};