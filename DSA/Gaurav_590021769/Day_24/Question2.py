class Solution(object):
    def sortedSquares(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        n = len(nums)
        result = [0] * n

        left = 0
        right = n - 1
        pos = n - 1

        while left <= right:
            if nums[left] * nums[left] > nums[right] * nums[right]:
                result[pos] = nums[left] * nums[left]
                left += 1
            else:
                result[pos] = nums[right] * nums[right]
                right -= 1
            pos -= 1

        return result