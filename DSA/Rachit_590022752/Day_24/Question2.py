n = int(input("Enter the number of elements: "))
arr = list(map(int, input("Enter the sorted array elements: ").split()))

squares = [x * x for x in arr]
squares.sort()

print("Sorted squares:", *squares)
