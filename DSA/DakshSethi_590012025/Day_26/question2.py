def has_triplet(arr):
    s = set(arr)
    n = len(arr)

    for i in range(n):
        for j in range(i + 1, n):
            if arr[i] + arr[j] in s:
                return True
    return False


arr = list(map(int, input("Enter numbers separated by space: ").split()))

print(has_triplet(arr))