#include <bits/stdc++.h>
using namespace std;

int compress(vector<char>& chars) {
    int n = chars.size();
    int index = 0;
    int i = 0;

    while (i < n) {
        char current = chars[i];
        int count = 0;

        while (i < n && chars[i] == current) {
            count++;
            i++;
        }

        chars[index++] = current;

        if (count > 1) {
            string s = to_string(count);
            for (char c : s) {
                chars[index++] = c;
            }
        }
    }

    return index;
}

int main() {
    vector<char> chars = {'a','a','b','b','c','c','c'};

    int len = compress(chars);

    cout << "Compressed Length = " << len << endl;
    cout << "Compressed Array = ";

    for (int i = 0; i < len; i++)
        cout << chars[i] << " ";

    return 0;
}