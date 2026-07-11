n = int(input())
arr = list(map(int, input().split()))
l, r = map(int, input().split())

ans = 0
curr = 0

for x in arr:
    if x <= r:
        curr += 1
    else:
        curr = 0
    ans += curr

temp = 0
curr = 0

for x in arr:
    if x < l:
        curr += 1
    else:
        curr = 0
    temp += curr

print(ans - temp)