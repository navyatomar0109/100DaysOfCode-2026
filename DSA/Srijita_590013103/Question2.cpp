class Solution {
public:
    int countBound(vector<int>& arr, int bound) {
        int count = 0;
        int ans = 0;

        for (int i = 0; i < arr.size(); i++) {

            if (arr[i] <= bound)
                count++;
            else
                count = 0;

            ans += count;
        }

        return ans;
    }

    int countSubarrays(vector<int>& arr, int l, int r) {

        return countBound(arr, r) - countBound(arr, l - 1);
    }
};