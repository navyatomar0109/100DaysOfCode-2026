nums = list(map(int, input().split()))

result = []

for num in nums:
    result.append(num * num)

result.sort()

print(result)
