def countBounded(arr, l, r):
    ans = 0
    count = 0
    last = -1
    for i in range(len(arr)):
        if arr[i] > r:
            count = 0
            last = i
        elif arr[i] >= l:
            count = i - last
        ans += count
    return ans
arr = list(map(int, input().split()))
l = int(input())
r = int(input())
git add DSA/Sanskriti_590025603/Day_27print(countBounded(arr, l, r))