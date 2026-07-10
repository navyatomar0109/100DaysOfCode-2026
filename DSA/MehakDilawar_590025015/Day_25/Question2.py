#Given a sorted array of integers and a target value, determine whether there exists a pair of elements whose sum
#is equal to the target. Return true if such a pair exists; otherwise, return false.
#Input:arr = [1, 2, 4, 6, 10] target = 8. Output:true.
def sum_pair(arr, target):
    left = 0
    right = len(arr) - 1
    while left < right:
        current_sum = arr[left] + arr[right]
        if current_sum == target:
            return True
        elif current_sum < target:
            left += 1
        else:
            right -= 1
    return False

arr = list(map(int, input("Enter sorted array elements: ").split()))
target = int(input("Enter target: "))
if sum_pair(arr, target):
    print("true")
else:
    print("false")