class Solution(object):
    def tripletSumCheck(self, arr):
        arr.sort()
        n = len(arr)

        for k in range(n - 1, 1, -1):
            left = 0
            right = k - 1

            while left < right:
                s = arr[left] + arr[right]

                if s == arr[k]:
                    return True
                elif s < arr[k]:
                    left += 1
                else:
                    right -= 1

        return False

arr = [4, 1, 3, 2, 5]

sol = Solution()
print(sol.tripletSumCheck(arr))
