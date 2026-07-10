arr = list(map(int, input().split()))
target = int(input())
left = 0
right = len(arr) - 1
found = False
while left < right:
    s = arr[left] + arr[right]
    if s == target:
        found = True
        break
    elif s < target:
        left += 1
    else:
        right -= 1
print(found)