def count_occurrences(arr, target):

    left, right = 0, len(arr) - 1
    first = -1

    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            first = mid
            right = mid - 1
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    if first == -1:
        return 0

   
    left, right = 0, len(arr) - 1
    last = -1

    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            last = mid
            left = mid + 1
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    return last - first + 1
arr = [1, 1, 2, 2, 2, 2]
target = 2

print(count_occurrences(arr, target))
