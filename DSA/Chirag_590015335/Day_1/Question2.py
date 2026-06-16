def find_sum(arr):
    total = 0

    for num in arr:
        total += num

    return total

arr = [12, 35, 1, 10, 34, 1]

result = find_sum(arr)
print("Array =", arr)
print("Sum =", result)