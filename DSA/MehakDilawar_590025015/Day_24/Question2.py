#Given a sorted array, return a new array containing the squares of each element, also sorted in non decreasing order.
#Input:nums = [-4,-1,0,3,10]. Output:[0,1,9,16,100]
def Squares(nums):
    n = len(nums)
    result = [0] * n
    left=0
    right=n-1
    pos = n-1
    while left <= right:
        if abs(nums[left]) > abs(nums[right]):
            result[pos] = nums[left] ** 2
            left += 1
        else:
            result[pos] = nums[right] ** 2
            right -= 1
        pos -= 1
    return result

nums = list(map(int, input("Enter sorted numbers separated by spaces: ").split()))
print(Squares(nums))