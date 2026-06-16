#include <iostream>
using namespace std;

int main() {

    int arr[] = {3, 7, 9, 2, 5};

    int n = sizeof(arr) / sizeof(arr[0]); // Total number of elements

    int largest = arr[0];

    for (int i = 1; i < n; i++) {

        if (arr[i] > largest) { // Updating largest element
            largest = arr[i];
        }
    }

    cout << largest;

    return 0;
}
