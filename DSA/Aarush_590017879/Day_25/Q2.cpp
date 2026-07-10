#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;
    cin >> target;

    int left = 0, right = n - 1;
    bool found = false;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (sum == target) {
            found = true;
            break;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }

    cout << (found ? "true" : "false") << endl;

    return 0;
}