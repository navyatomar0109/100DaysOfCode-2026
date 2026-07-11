#include<iostream>
#include<vector>
using namespace std;

void sortcolours(vector<int>& colours) {
    int low = 0, mid = 0, high = colours.size() - 1;
    while (mid <= high) {
        switch (colours[mid]) {
            case 0:
                swap(colours[low++], colours[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(colours[mid], colours[high--]);
                break;
        }
    }
}
int main() {
    vector<int> colours = {2, 0, 2, 1, 1, 0};
    sortcolours(colours);
    for (int i = 0; i < colours.size(); i++) {
        cout << colours[i] << " ";
    }
    return 0;
}