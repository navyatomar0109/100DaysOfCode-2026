n = int(input("length = "))
arr = sorted([int(input(f"num {i+1} = ")) for i in range(n)])
print(arr[n-1])