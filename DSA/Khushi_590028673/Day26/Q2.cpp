#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool tripletSumCheck(vector<int>& arr) {
    int n = arr.size();

    // Sort the array
    sort(arr.begin(), arr.end());

    // Pick each element as the target (largest element)
    for (int i = n - 1; i >= 2; i--) {
        int left = 0;
        int right = i - 1;

        while (left < right) {
            int sum = arr[left] + arr[right];

            if (sum == arr[i]) {
                return true;
            } 
            else if (sum < arr[i]) {
                left++;
            } 
            else {
                right--;
            }
        }
    }

    return false;
}

int main() {
    vector<int> arr = {4, 1, 3, 2, 5};

    if (tripletSumCheck(arr))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}
