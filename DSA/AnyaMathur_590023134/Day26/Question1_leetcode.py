# Leetcode Problem 75
# Sort Colors 

class Solution(object):
    def sortColors(self, nums):
        start = 0
        temp = 0
        end = len(nums) - 1

        while temp <= end:
            if nums[temp] == 0:
                nums[start], nums[temp] = nums[temp], nums[start]
                start += 1
                temp += 1
            elif nums[temp] == 1:
                temp += 1
            else:
                nums[temp], nums[end] = nums[end], nums[temp]
                end -= 1