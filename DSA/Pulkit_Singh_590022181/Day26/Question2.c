class Solution {
public:
    bool findTriplet(vector<int>& arr) {

        sort(arr.begin(), arr.end());
        int n = arr.size();

        for (int k = n - 1; k >= 2; k--) {

            int i = 0;
            int j = k - 1;

            while (i < j) {

                int sum = arr[i] + arr[j];

                if (sum == arr[k])
                    return true;
                else if (sum < arr[k])
                    i++;
                else
                    j--;
            }
        }

        return false;
    }
};