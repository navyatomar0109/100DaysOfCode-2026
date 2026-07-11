# Subarrays with Bounded Maximum

def count_subarrays(arr, limit):
    count = 0
    current = 0

    for num in arr:
        if num <= limit:
            current += 1
        else:
            current = 0

        count += current

    return count


def bounded_max_subarrays(arr, l, r):
    return count_subarrays(arr, r) - count_subarrays(arr, l - 1)


n = int(input("Enter the number of elements: "))

print("Enter the array elements:")
arr = list(map(int, input().split()))

l = int(input("Enter l: "))
r = int(input("Enter r: "))

result = bounded_max_subarrays(arr, l, r)

print("Number of subarrays with maximum in the range [l, r]:", result)