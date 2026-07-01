def countOccurrences(arr, target):
    count = 0

    for num in arr:
        if num == target:
            count += 1

    return count


# Input
arr = list(map(int, input("Enter array elements: ").split()))
target = int(input("Enter target: "))

# Output
print(countOccurrences(arr, target))
