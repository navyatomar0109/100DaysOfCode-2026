#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool tripletSumCheck(vector<int>& arr)
{
    int n = arr.size();

    sort(arr.begin(), arr.end());

    for(int k = n - 1; k >= 2; k--)
    {
        int i = 0;
        int j = k - 1;

        while(i < j)
        {
            int sum = arr[i] + arr[j];

            if(sum == arr[k])
                return true;

            else if(sum < arr[k])
                i++;

            else
                j--;
        }
    }

    return false;
}

int main()
{
    vector<int> arr = {4,1,3,2,5};

    if(tripletSumCheck(arr))
        cout << "true";
    else
        cout << "false";

    return 0;
}