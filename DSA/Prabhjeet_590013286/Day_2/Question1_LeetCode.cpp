#include <vector>

class Solution {
public:

    int removeElement(vector<int>& nums, int val) {

        int k = 0;

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] != val) { // Keeping elements not equal to val

                nums[k] = nums[i];
                k++;
            }
        }

        return k; // Number of remaining elements
    }
};