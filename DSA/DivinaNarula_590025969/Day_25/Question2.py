# Pair with Target Sum

def pair_with_target_sum(arr, target):
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

arr = list(map(int, input("Enter the sorted array: ").split()))
target = int(input("Enter the target: "))

if pair_with_target_sum(arr, target):
    print("True")
else:
    print("False")