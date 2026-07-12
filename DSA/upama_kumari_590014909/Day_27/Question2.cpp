#include <bits/stdc++.h>
using namespace std;

long long countSubarrays(vector<int>& arr, int k)
{
    long long ans = 0;
    long long len = 0;

    for (int x : arr)
    {
        if (x <= k)
        {
            len++;
            ans += len;
        }
        else
        {
            len = 0;
        }
    }

    return ans;
}

long long numSubarrayBoundedMax(vector<int>& arr, int l, int r)
{
    return countSubarrays(arr, r) - countSubarrays(arr, l - 1);
}

int main()
{
    vector<int> arr = {1,2,3,4,5};

    int l = 2;
    int r = 5;

    cout << numSubarrayBoundedMax(arr, l, r);

    return 0;
}