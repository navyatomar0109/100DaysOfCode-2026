#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool tripletExists(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    for(int i = n - 1; i >= 2; i--) {
        int left = 0;
        int right = i - 1;
        while(left < right) {
            int sum = arr[left] + arr[right];
            if(sum == arr[i])
                return true;
            if(sum < arr[i])
                left++;
            else
                right--;
        }
    }
    return false;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the array elements: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    if(tripletExists(arr))
        cout << "true";
    else
        cout << "false";
    return 0;
}
