def count(arr, bound):
    ans = 0
    curr = 0

    for num in arr:
        if num <= bound:
            curr += 1
        else:
            curr = 0
        ans += curr

    return ans


def bounded_max_subarrays(arr, l, r):
    return count(arr, r) - count(arr, l - 1)


# Input
arr = list(map(int, input().split()))
l, r = map(int, input().split())

# Output
print(bounded_max_subarrays(arr, l, r))
