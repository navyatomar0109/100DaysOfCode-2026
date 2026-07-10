//Given a sorted array of integers and a target value, determine whether there exists a pair of elements whose sum is equal to the target.
// Return true if such a pair exists; otherwise, return false

#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter the size of array: ";
    cin >> n;

    int arr[n];

    cout << "Enter the sorted array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;
    cout << "Enter the target sum: ";
    cin >> target;

    int left = 0;
    int right = n - 1;

    bool found = false;

    while(left < right) {

        int sum = arr[left] + arr[right];

        if(sum == target) {
            found = true;
            break;
        }
        else if(sum < target) {
            left++;
        }
        else {
            right--;
        }
    }

    if(found)
        cout << "True";
    else
        cout << "False";

    return 0;
}