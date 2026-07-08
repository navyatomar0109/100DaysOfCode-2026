#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.length() - 1;
        int j = t.length() - 1;
        
        int skipS = 0; // Number of backspaces to apply in string s
        int skipT = 0; // Number of backspaces to apply in string t
        
        // Single loop processing both pointers backwards
        while (i >= 0 || j >= 0) {
            
            // 1. Find the next valid character in string s
            while (i >= 0) {
                if (s[i] == '#') {
                    skipS++;
                    i--;
                } else if (skipS > 0) {
                    skipS--;
                    i--;
                } else {
                    break; // Found a valid character
                }
            }
            
            // 2. Find the next valid character in string t
            while (j >= 0) {
                if (t[j] == '#') {
                    skipT++;
                    j--;
                } else if (skipT > 0) {
                    skipT--;
                    j--;
                } else {
                    break; // Found a valid character
                }
            }
            
            // 3. Compare the two valid characters
            // If one pointer is valid and the other is out of bounds, they don't match
            if ((i >= 0) != (j >= 0)) {
                return false;
            }
            
            // If both are valid, check if the actual characters match
            if (i >= 0 && j >= 0 && s[i] != t[j]) {
                return false;
            }
            
            // Move both pointers down to continue checking
            i--;
            j--;
        }
        
        return true;
    }
};

int main() {
    Solution solver;
    string s = "ab#c";
    string t = "ad#c";

    if (solver.backspaceCompare(s, t)) {
        cout << "Result: true" << endl;
    } else {
        cout << "Result: false" << endl;
    }

    return 0;
}