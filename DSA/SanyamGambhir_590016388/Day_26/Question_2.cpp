#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; i++) {

            // Skip duplicate values for the first element
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum < 0) {
                    j++;
                }
                else if (sum > 0) {
                    k--;
                }
                else {
                    ans.push_back({nums[i], nums[j], nums[k]});

                    j++;
                    k--;

                    // Skip duplicate values for the second element
                    while (j < k && nums[j] == nums[j - 1])
                        j++;

                    // Skip duplicate values for the third element
                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                }
            }
        }

        return ans;
    }
};

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution obj;
    vector<vector<int>> ans = obj.threeSum(nums);

    if (ans.empty()) {
        cout << "No Triplets Found\n";
    } else {
        cout << "Triplets are:\n";
        for (auto &triplet : ans) {
            cout << "[ ";
            for (int x : triplet) {
                cout << x << " ";
            }
            cout << "]\n";
        }
    }

    return 0;
}