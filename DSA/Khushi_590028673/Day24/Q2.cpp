#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
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
};

int main() {
    Solution obj;

    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter the sorted array elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> result = obj.sortedSquares(nums);

    cout << "Sorted Squares Array: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
