arr = list(map(int, input("Enter the sorted array: ").split()))
target = int(input("Enter the target: "))

left = 0
right = len(arr) - 1

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

if found:
    print("true")
else:
    print("false")