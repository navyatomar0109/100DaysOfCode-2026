#include <iostream>
#include <string>
using namespace std;

string processString(string str) {
    string result;

    for (char ch : str) {
        if (ch == '#') {
            if (!result.empty()) {
                result.pop_back();
            }
        } else {
            result.push_back(ch);
        }
    }

    return result;
}

int main() {
    string s, t;

    cin >> s >> t;

    if (processString(s) == processString(t)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}