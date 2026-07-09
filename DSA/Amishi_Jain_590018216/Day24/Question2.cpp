//Given a sorted array, return a new array containing the squares of each element, also sorted in non decreasing order.
// This is LeetCode 977: Squares of a Sorted Array.

//bruteforce approach time complexity = O(n log n)

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr[] = {-4, -1, 0, 3, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        arr[i] = arr[i] * arr[i];
    }

    sort(arr, arr + n);

    cout << "Sorted Squares: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}