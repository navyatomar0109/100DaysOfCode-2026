//Triplet Sum Check Determine whether an array contains three elements such that the sum of any two elements is equal to the third element, and return true if such a triplet exists; otherwise, return false.
//brute force approach

// #include <iostream>
// using namespace std;

// int main() {
//     int n;

//     cout << "Enter the size of array: ";
//     cin >> n;

//     int arr[n];

//     cout << "Enter the array elements: ";
//     for(int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }

//     bool found = false;

//     for(int i = 0; i < n - 2; i++) {
//         for(int j = i + 1; j < n - 1; j++) {
//             for(int k = j + 1; k < n; k++) {

//                 if(arr[i] + arr[j] == arr[k] ||
//                    arr[i] + arr[k] == arr[j] ||
//                    arr[j] + arr[k] == arr[i]) {

//                     found = true;
//                     break;
//                 }
//             }
//             if(found)
//                 break;
//         }
//         if(found)
//             break;
//     }

//     if(found)
//         cout << "True";
//     else
//         cout << "False";

//     return 0;
// }

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;

    cout << "Enter the size of array: ";
    cin >> n;

    int arr[n];

    cout << "Enter the array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    bool found = false;

    for(int i = n - 1; i >= 2; i--) {

        int left = 0;
        int right = i - 1;

        while(left < right) {

            int sum = arr[left] + arr[right];

            if(sum == arr[i]) {
                found = true;
                break;
            }
            else if(sum < arr[i]) {
                left++;
            }
            else {
                right--;
            }
        }

        if(found)
            break;
    }

    if(found)
        cout << "True";
    else
        cout << "False";

    return 0;
}