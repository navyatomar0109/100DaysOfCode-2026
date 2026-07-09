def pairWithTarget(arr, target):
    left = 0
    right = len(arr) - 1

    while left < right:
        s = arr[left] + arr[right]

        if s == target:
            return True
        elif s < target:
            left += 1
        else:
            right -= 1

    return False


# Example
arr = [1, 2, 4, 6, 10]
target = 8

print(pairWithTarget(arr, target))
