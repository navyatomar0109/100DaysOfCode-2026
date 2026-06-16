class Solution:
    def missingNumber(self, nums):
        n = len(nums)
        expected = n * (n + 1) // 2
        actual = sum(nums)
        return expected - actual

nums = [3, 0, 1]
sol = Solution()
result = sol.missingNumber(nums)
print(result)