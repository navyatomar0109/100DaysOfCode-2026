/*Find the Sum of Array Elements
Explanation
Write an efficient function to calculate the sum of all elements in an integer array.

Example
Input: [3, 8, 2, 9, 1]. Output: 23.
*/

#include <iostream>
using namespace std;

int main() {

    int arr[] = {12, 35, 1, 10, 34, 1};  

    int n = sizeof(arr) / sizeof(arr[0]); // Total number of elements

    int sum = 0;                          

    for (int i = 0; i < n; i++) {
        sum += arr[i];                    // Adding each element
    }

    cout << sum;                          

    return 0;                             
}