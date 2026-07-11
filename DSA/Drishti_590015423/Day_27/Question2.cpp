class Solution {
public:
    long long countSubarrays(vector<int>& arr, int l, int r) {
        return count(arr, r) - count(arr, l - 1);
    }

private:
    long long count(vector<int>& arr, int x) {
        long long ans = 0;
        long long len = 0;

        for (int num : arr) {
            if (num <= x)
                len++;
            else
                len = 0;

            ans += len;
        }

        return ans;
    }
};
