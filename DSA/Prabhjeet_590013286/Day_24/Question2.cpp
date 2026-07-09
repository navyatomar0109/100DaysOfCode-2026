//Need to return the squares in sorted order

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> nums = {-4, -1, 0, 3, 10};

    int left = 0;
    int right = nums.size() - 1;

    vector<int> ans(nums.size());

    int index = nums.size() - 1;

    // bigger square will always come from one of the ends
    while (left <= right)
    {
        int leftSquare = nums[left] * nums[left];
        int rightSquare = nums[right] * nums[right];

        if (leftSquare > rightSquare)
        {
            ans[index] = leftSquare;
            left++;
        }
        else
        {
            ans[index] = rightSquare;
            right--;
        }

        index--;
    }

    for (int num : ans)
    {
        cout << num << " ";
    }

    return 0;
}