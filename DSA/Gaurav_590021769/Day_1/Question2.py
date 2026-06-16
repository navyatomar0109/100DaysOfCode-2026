def arraySum(nums):
    total = 0

    for num in nums:
        total += num

    return total
nums = [3, 8, 2, 9, 1]
print(arraySum(nums))