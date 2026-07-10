arr = [4, 1, 3, 2, 5]

arr.sort()
n = len(arr)
found = False

for i in range(n - 1, 1, -1):
    left = 0
    right = i - 1

    while left < right:
        s = arr[left] + arr[right]

        if s == arr[i]:
            found = True
            break
        elif s < arr[i]:
            left += 1
        else:
            right -= 1

    if found:
        break

print(found)