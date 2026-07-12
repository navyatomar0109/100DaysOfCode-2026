def count(arr, bound):
    result = 0
    current = 0

    for num in arr:
        if num <= bound:
            current += 1
        else:
            current = 0
        result += current

    return result

n = int(input("Enter the number of elements: "))
arr = list(map(int, input("Enter the array elements: ").split()))

l = int(input("Enter the lower bound (l): "))
r = int(input("Enter the upper bound (r): "))

answer = count(arr, r) - count(arr, l - 1)

print("Number of subarrays with bounded maximum:", answer)
