n = int(input("Enter the number of elements: "))
arr =list(input("Enter the elements: ").split())
arr = [int(x) for x in arr]

found = False

for i in range(n):
    for j in range(i + 1, n):
        for k in range(j + 1, n):
            if (arr[i] + arr[j] == arr[k] or
                arr[i] + arr[k] == arr[j] or
                arr[j] + arr[k] == arr[i]):
                found = True

if found:
    print("True")
else:
    print("False")
