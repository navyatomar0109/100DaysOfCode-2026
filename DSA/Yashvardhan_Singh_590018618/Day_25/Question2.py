arr = list()
arrLen = int(input("Enter array length: "))
for i in range(arrLen):
    arr.append(int(input(f"Enter number {i + 1}: ")))

target = int(input("Enter target: "))

def targetSum(arr, target):
    for k in range(2, len(arr)+1):
        i = 0
        j = k - 1
        while i < j:
            if arr[i] + arr[j] == target:
                return True
            else:
                i += 1
    return False

print(targetSum(arr, target))