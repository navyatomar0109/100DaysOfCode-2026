//Need to check if any two numbers add up to a third one

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool hasTriplet(vector<int>& arr)
{
    sort(arr.begin(), arr.end());

    // treating every element as the possible sum
    for (int i = arr.size() - 1; i >= 2; i--)
    {
        int left = 0;
        int right = i - 1;

        while (left < right)
        {
            int sum = arr[left] + arr[right];

            if (sum == arr[i])
            {
                return true;
            }

            if (sum < arr[i])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }

    return false;
}

int main()
{
    vector<int> arr = {4, 1, 3, 2, 5};

    if (hasTriplet(arr))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }

    return 0;
}