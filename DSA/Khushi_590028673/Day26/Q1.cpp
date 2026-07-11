#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int count0 = 0, count1 = 0, count2 = 0;

        // Count 0s, 1s, and 2s
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)
                count0++;
            else if (nums[i] == 1)
                count1++;
            else
                count2++;
        }

        int index = 0;

        // Fill 0s
        while (count0 > 0) {
            nums[index] = 0;
            index++;
            count0--;
        }

        // Fill 1s
        while (count1 > 0) {
            nums[index] = 1;
            index++;
            count1--;
        }

        // Fill 2s
        while (count2 > 0) {
            nums[index] = 2;
            index++;
            count2--;
        }
    }
};

int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    Solution obj;
    obj.sortColors(nums);

    cout << "Sorted Array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
