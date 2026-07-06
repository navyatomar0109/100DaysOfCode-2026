s = input().strip()

distinct = len(set(s))

f = {}
left = 0
count = 0
ans = len(s)

for right in range(len(s)):
    ch = s[right]

    if ch in f:
        f[ch] += 1
    else:
        f[ch] = 1
        count += 1

    while count == distinct:
        ans = min(ans, right - left + 1)

        f[s[left]] -= 1
        if f[s[left]] == 0:
            count -= 1
        left += 1

print(ans)