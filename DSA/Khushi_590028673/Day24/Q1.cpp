#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    // Function to calculate the sum of squares of digits
    int squareSum(int n) {
        int sum = 0;

        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }

        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int> seen;

        while (n != 1 && seen.find(n) == seen.end()) {
            seen.insert(n);
            n = squareSum(n);
        }

        return n == 1;
    }
};

int main() {
    Solution obj;

    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (obj.isHappy(n))
        cout << n << " is a Happy Number." << endl;
    else
        cout << n << " is NOT a Happy Number." << endl;

    return 0;
}
