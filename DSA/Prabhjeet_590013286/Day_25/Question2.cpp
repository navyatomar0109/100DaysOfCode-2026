//Need to check if any pair adds up to the target

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> nums = {1, 2, 4, 6, 10};
    int target = 8;

    int left = 0;
    int right = nums.size() - 1;

    // keep moving towards the target
    while (left < right)
    {
        int sum = nums[left] + nums[right];

        if (sum == target)
        {
            cout << "true";
            return 0;
        }

        if (sum < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }

    cout << "false";

    return 0;
}