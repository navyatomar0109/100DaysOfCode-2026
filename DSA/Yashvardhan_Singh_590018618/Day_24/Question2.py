arrSize = int(input("Enter array size: "))
arr = []
for i in range(arrSize):
    arr.append(int(input(f"Enter Number {i+1}: ")))
    
def sortedSquares(arr):
    for i in range(len(arr)):
        arr[i] = arr[i] ** 2
    return arr

arr = sortedSquares(arr)
for i in range(len(arr)):
    for j in range(len(arr)):
        if arr[i] < arr[j] :
            arr[j], arr[i] = arr[i], arr[j]
        
print(arr)