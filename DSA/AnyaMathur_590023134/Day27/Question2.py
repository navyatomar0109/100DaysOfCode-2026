# Problem 2 
# Subarrays with Bounded Maximum

def countSubarrays(arr, limit):
    count = 0
    length = 0

    for num in arr:
        if num <= limit:
            length += 1
        else:
            length = 0

        count += length

    return count

arr = list(map(int, input("Enter array elements: ").split()))
l = int(input("Enter l: "))
r = int(input("Enter r: "))

answer = countSubarrays(arr, r) - countSubarrays(arr, l - 1)

print("Number of valid subarrays =", answer)