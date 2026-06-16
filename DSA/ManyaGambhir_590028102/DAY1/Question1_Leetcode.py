class Solution:
    def missingNumber(self, nums):
        missing = len(nums)
        
        for i in range(len(nums)):
            missing ^= i ^ nums[i]
            
        return missing