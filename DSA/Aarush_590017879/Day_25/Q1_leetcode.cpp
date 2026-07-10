#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    int count = 0;

    for (int k = n - 1; k >= 2; k--) {
        int left = 0;
        int right = k - 1;

        while (left < right) {
            if (nums[left] + nums[right] > nums[k]) {
                count += (right - left);
                right--;
            } else {
                left++;
            }
        }
    }

    cout << count << endl;

    return 0;
}