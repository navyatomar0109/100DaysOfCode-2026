nums = list(map(int, input("Enter sorted numbers: ").split()))

result = []

for i in nums:
    result.append(i * i)

result.sort()

print(result)