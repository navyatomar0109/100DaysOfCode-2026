arr = list(map(int, input("Enter the sorted array elements (space-separated): ").split()))

target = int(input("Enter the target sum: "))

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
    print("True")
    print(f"Pair found: {arr[left]} + {arr[right]} = {target}")
else:
    print("False")
    print("No pair with the given target sum exists.")
