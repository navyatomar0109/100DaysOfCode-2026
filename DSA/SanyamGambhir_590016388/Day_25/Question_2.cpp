#include <iostream>
#include <vector>

class Solution {
public:
    /**
     * Determines if there exists a pair of elements in a sorted array 
     * whose sum equals the given target.
     * * @param arr A sorted vector of integers.
     * @param target The target sum to find.
     * @return true if such a pair exists, false otherwise.
     */
    bool hasPairWithTarget(const std::vector<int>& arr, int target) {
        if (arr.size() < 2) return false;

        int left = 0;
        int right = arr.size() - 1;

        while (left < right) {
            int currentSum = arr[left] + arr[right];

            if (currentSum == target) {
                return true; // Pair found
            } else if (currentSum < target) {
                left++; // Increase sum by moving the left pointer right
            } else {
                right--; // Decrease sum by moving the right pointer left
            }
        }

        return false; // No such pair exists
    }
};

int main() {
    Solution solver;

    // Test Example from the challenge
    std::vector<int> arr = {1, 2, 4, 6, 10};
    int target = 8;

    if (solver.hasPairWithTarget(arr, target)) {
        std::cout << "Does pair exist? true" << std::endl;
    } else {
        std::cout << "Does pair exist? false" << std::endl;
    }

    return 0;
}