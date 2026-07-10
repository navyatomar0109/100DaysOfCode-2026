//To form a triangle with three sides a, b, c, the rule is: a + b > c (assuming a ≤ b ≤ c)
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
         sort(nums.begin(), nums.end());
        int n = nums.size();
        int count = 0;

        for (int i = n - 1; i >= 2; i--) {
            int left = 0, right = i - 1;
            while (left < right) {
                if (nums[left] + nums[right] > nums[i]) {
                    count += right - left;
                    right--;
                } else {
                    left++;
                }
            }
        }
        return count;
    }
};