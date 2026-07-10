n=int(input("Enter size: "))
arr=[]
for i in range(n):
    a=int(input("Enter element: "))
    arr.append(a)
target=int(input("Enter target: "))
arr.sort()
l=0
r=n-1
found=False
while l<r:
    s=arr[l]+arr[r]
    if s==target:
        found=True
        break
    elif s<target:
        l=l+1
    else:
        r=r-1
print(f"Ouput:{found}")
