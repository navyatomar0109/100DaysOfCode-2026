def countSubarrays(arr, l, r):
    ans = 0
    left = -1
    right = -1

    for i in range(len(arr)):
        if arr[i] > r:
            left = i

        if l <= arr[i] <= r:
            right = i

        ans += max(0, right - left)

    return ans


arr = [1, 2, 3, 4, 5]
l = 2
r = 5

print(countSubarrays(arr, l, r))