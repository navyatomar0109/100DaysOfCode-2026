class Solution {
public:

    void swipe(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    void sortColors(vector<int>& nums) {

        int r = 0;

        // Pass 1: Move all 0s to the front
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                swipe(nums[i], nums[r]);
                r++;
            }
        }

        int w = r;

        // Pass 2: Move all 1s after the 0s
        for(int i = r; i < nums.size(); i++)
        {
            if(nums[i] == 1)
            {
                swipe(nums[i], nums[w]);
                w++;
            }
        }
    }
};