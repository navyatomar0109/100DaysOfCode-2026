class Solution {
public:
    bool pairExists(vector<int>& arr, int target) {
        int left = 0;
        int right = arr.size() - 1;
        while (left < right) {
            int sum = arr[left] + arr[right];
            if (sum == target)
                return true;
            if (sum < target)
                left++;
            else
                right--;
        }
        return false;
    }
};