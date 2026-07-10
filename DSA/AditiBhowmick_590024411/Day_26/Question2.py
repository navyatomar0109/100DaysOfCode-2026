arr = list(map(int, input("Enter the array elements: ").split()))

n = len(arr)
found = False
arr.sort()

for k in range(n - 1, 1, -1):
    left = 0
    right = k - 1

    while left < right:
        s = arr[left] + arr[right]

        if s == arr[k]:
            found = True
            break
        elif s < arr[k]:
            left += 1
        else:
            right -= 1

    if found:
        break

if found:
    print("true")
else:
    print("false")