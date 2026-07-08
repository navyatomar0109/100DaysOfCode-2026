#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;

    // Number of children
    cin >> n;
    vector<int> g(n);

    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }

    // Number of cookies
    cin >> m;
    vector<int> s(m);

    for (int i = 0; i < m; i++) {
        cin >> s[i];
    }

    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int child = 0, cookie = 0;

    while (child < n && cookie < m) {
        if (s[cookie] >= g[child]) {
            child++;
        }
        cookie++;
    }

    cout << child << endl;

    return 0;
}