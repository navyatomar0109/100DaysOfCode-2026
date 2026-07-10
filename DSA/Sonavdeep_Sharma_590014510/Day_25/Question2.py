n = int(input("Enter number of elements: "))
arr = list(map(int, input("Enter the sorted array elements : ").split()))
target = int(input("Enter the target sum: "))

left = 0
right = n - 1
found = False

while left < right:
    current_sum = arr[left] + arr[right]

    if current_sum == target:
        found = True
        break
    elif current_sum < target:
        left += 1
    else:
        right -= 1

print("true" if found else "false")