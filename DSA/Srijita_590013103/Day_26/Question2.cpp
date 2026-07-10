class Solution {
public:
    bool TripletSum(vector<int> &arr) {
        int n = arr.size();
        if (n < 3)
            return false;
        sort(arr.begin(), arr.end());
        for (int i = n - 1; i >= 2; i--) {
            int low = 0;
            int high = i - 1;
            while (low < high) {
                int sum = arr[low] + arr[high];
                if (sum == arr[i]) {
                    return true;
                }
                else if (sum < arr[i]) {
                    low++;
                }
                else {
                    high--;
                }
            }
        }

        return false;
    }
};