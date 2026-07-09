class Solution(object):
    def hasPairWithTargetSum(self, arr, target):
        left = 0
        right = len(arr) - 1

        while left < right:
            curr_sum = arr[left] + arr[right]

            if curr_sum == target:
                return True
            elif curr_sum < target:
                left += 1
            else:
                right -= 1

        return False

arr = [1, 2, 4, 6, 10]
target = 8

obj = Solution()
print(obj.hasPairWithTargetSum(arr, target))
