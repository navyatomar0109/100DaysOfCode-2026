def triplet_sum_check(arr):
    n = len(arr)
    arr.sort()

    for k in range(n - 1, -1, -1):
        i = 0
        j = k - 1

        while i < j:
            s = arr[i] + arr[j]

            if s == arr[k]:
                return True
            elif s < arr[k]:
                i += 1
            else:
                j -= 1

    return False


arr = list(map(int, input().split()))

print(triplet_sum_check(arr))
