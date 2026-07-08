class Solution:
    def sortedSquares(self, nums):
        left = 0
        right = len(nums) - 1
        ans = [0] * len(nums)

        for i in range(len(nums)-1, -1, -1):
            if abs(nums[left]) > abs(nums[right]):
                ans[i] = nums[left] * nums[left]
                left += 1
            else:
                ans[i] = nums[right] * nums[right]
                right -= 1

        return ans
