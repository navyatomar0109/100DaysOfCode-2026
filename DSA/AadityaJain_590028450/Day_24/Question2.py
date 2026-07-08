'''Squares of a Sorted Array
Explanation
Given a sorted array, return a new array containing the squares of each element, also sorted in non decreasing order.'''

nums = list(map(int, input("Enter sorted array elements: ").split()))

result = []

for num in nums:
    result.append(num * num)

result.sort()

print(result)