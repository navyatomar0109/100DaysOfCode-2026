class Solution {
public:
    int largestElement(vector<int>& nums) {
        int largestno = nums[0];
          for (int i = 0; i<nums.size(); i++) {
            if (nums[i] > largestno) {
               largestno = nums [i];
            }
        }
        return largestno;
    }
};