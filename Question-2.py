class Solution(object):
    def numSubarrayBoundedMax(self, arr, left, right):
        def count(bound):
            ans = 0
            curr = 0

            for num in arr:
                if num <= bound:
                    curr += 1
                else:
                    curr = 0
                ans += curr

            return ans

        return count(right) - count(left - 1)
