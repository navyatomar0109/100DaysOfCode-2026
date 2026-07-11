#include <iostream>
#include <vector>
using namespace std;

int countSubarrays(vector<int>& arr, int limit) {
    int count = 0;
    int current = 0;
    for(int value : arr) {
        if(value <= limit)
            current++;
        else
            current = 0;

        count += current;
    }
    return count;
}
int boundedSubarrays(vector<int>& arr, int left, int right) {
    return countSubarrays(arr, right) - countSubarrays(arr, left - 1);
}
int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the array elements: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int left, right;
    cout << "Enter the lower limit: ";
    cin >> left;
    cout << "Enter the upper limit: ";
    cin >> right;
    cout << "Number of valid subarrays: "
         << boundedSubarrays(arr, left, right);
    return 0;
}
