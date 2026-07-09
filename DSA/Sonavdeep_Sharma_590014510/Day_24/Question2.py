n = int(input("Enter the number of elements: "))
nums = list(map(int, input("Enter the sorted array elements: ").split()))

nums = [x * x for x in nums]
nums.sort()

print("Sorted squares:", *nums)