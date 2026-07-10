def tripletSumCheck(arr):
    arr.sort()
    n = len(arr)

    for i in range(n - 1, 1, -1):
        left = 0
        right = i - 1

        while left < right:
            s = arr[left] + arr[right]

            if s == arr[i]:
                return True
            elif s < arr[i]:
                left += 1
            else:
                right -= 1

    return False


arr = [4, 1, 3, 2, 5]
print(tripletSumCheck(arr))
