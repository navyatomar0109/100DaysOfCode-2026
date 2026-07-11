def pairWithTargetSum(arr, target):
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


# Driver Code
arr = list(map(int, input().split()))
target = int(input())

print(pairWithTargetSum(arr, target))