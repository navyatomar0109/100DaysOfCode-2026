# Problem 2 
# Triplet Sum Check

arr = list(map(int, input("Enter the elements: ").split()))
arr.sort()
found = False

for target in range(len(arr) - 1, 1, -1):
    left = 0
    right = target - 1
    
    while left < right:
        current_sum = arr[left] + arr[right]
        if current_sum == arr[target]:
            found = True
            break
        elif current_sum < arr[target]:
            left += 1
        else:
            right -= 1
    if found:
        break
    
if found:
    print("True")
else:
    print("False")