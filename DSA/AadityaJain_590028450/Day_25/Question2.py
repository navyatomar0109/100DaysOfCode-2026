'''Pair with Target Sum
Explanation
Given a sorted array of integers and a target value, determine whether there exists a pair of elements whose sum is equal to the target. Return true if such a pair exists; otherwise, return false.'''

arr = list(map(int, input("Enter sorted array elements: ").split()))
target = int(input("Enter target: "))

l = 0
r = len(arr) - 1

found = False

while l < r:
    s = arr[l] + arr[r]

    if s == target:
        found = True
        break
    elif s < target:
        l += 1
    else:
        r -= 1

print(found)