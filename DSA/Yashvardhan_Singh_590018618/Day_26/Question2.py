length = int(input("Enter array length: "))
arr = []
for i in range(length):
    arr.append(int(input(f"Enter number {i + 1}: ")))

def tripletSum(arr):
    for i in range(len(arr)):
        for j in range(len(arr)):
            if arr[i] > arr[j]:
                arr[i], arr[j] = arr[j], arr[i]
        
    for i in range(len(arr)):
        left = i + 1
        right = len(arr) - 1
        while left < right:
            if arr[left] + arr[right] == arr[i]:
                return True
            else:
                right -= 1
    return False
print(tripletSum(arr))