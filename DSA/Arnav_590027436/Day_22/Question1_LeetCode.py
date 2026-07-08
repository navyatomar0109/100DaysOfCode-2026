class Solution(object):
    def moveZeroes(self, nums):
        if len(nums) == 0 or len(nums) == 1:
            return nums
        
        zero_count = 0
        for i in range(len(nums)):
            if nums[i] == 0:
                zero_count += 1
            else:
                nums[i - zero_count], nums[i] = nums[i], nums[i - zero_count]

        return nums
        