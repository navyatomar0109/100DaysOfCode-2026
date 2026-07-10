#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int triangleNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int count = 0;

    for (int k = n - 1; k >= 2; k--) {
        int i = 0;
        int j = k - 1;

        while (i < j) {
            if (nums[i] + nums[j] > nums[k]) {
                count += (j - i);
                j--;
            } else {
                i++;
            }
        }
    }

    return count;
}

int main() {
    vector<int> nums = {2, 2, 3, 4};

    cout << triangleNumber(nums);

    return 0;
}