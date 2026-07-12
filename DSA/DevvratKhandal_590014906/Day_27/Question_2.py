nums = list(map(int, input("Enter array elements: ").split()))
left = int(input("Enter left value: "))
right = int(input("Enter right value: "))

def count(bound):
    result = 0
    current = 0

    for num in nums:
        if num <= bound:
            current += 1
        else:
            current = 0

        result += current

    return result

answer = count(right) - count(left - 1)

print("Number of valid subarrays =", answer)