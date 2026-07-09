def pair_with_target_sum(arr, target):
    left, right = 0, len(arr) - 1

    while left < right:
        s = arr[left] + arr[right]
        if s == target:
            return True
        elif s < target:
            left += 1
        else:
            right -= 1

    return False


arr = [1, 2, 4, 6, 10]
target = 8
print(pair_with_target_sum(arr, target))