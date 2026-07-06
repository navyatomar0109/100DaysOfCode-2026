class Solution:
    def rotate(self, nums, k):
        n = len(nums)
        k = k % n 
        nums[:] = nums[-k:] + nums[:-k]

        nums = [1, 2, 3, 4]
        k = 3
        Solution().rotate(nums, k)
        print(nums)