#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n);

    int left = 0;
    int right = n - 1;
    int index = n - 1;

    while (left <= right) {
        if (abs(nums[left]) > abs(nums[right])) {
            ans[index] = nums[left] * nums[left];
            left++;
        } else {
            ans[index] = nums[right] * nums[right];
            right--;
        }
        index--;
    }

    return ans;
}

int main() {
    vector<int> nums = {-4, -1, 0, 3, 10};

    vector<int> result = sortedSquares(nums);

    for (int x : result)
        cout << x << " ";

    return 0;
}