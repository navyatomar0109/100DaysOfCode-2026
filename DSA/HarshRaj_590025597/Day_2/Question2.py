def find_largest(arr):
    if not arr:
        return None
    
    largest = arr[0]
    for num in arr[1:]:
        if num > largest:
            largest = num
    return largest

# Get input from user
user_input = input("Enter array elements separated by spaces: ")
arr = list(map(int, user_input.split()))

result = find_largest(arr)
print(f"Largest element: {result}")