n=int(input("Enter size: "))
arr=[]
for i in range(n):
    a=int(input("Enter element: "))
    arr.append(a)
arr.sort()
found=False
for i in range(n-1,1,-1):
    l=0
    r=i-1
    while l<r:
        s=arr[l]+arr[r]
        if s==arr[i]:
            found=True
            break
        elif s<arr[i]:
            l=l+1
        else:
            r=r-1
    if found:
        break
print(f"OUTPUT:{found}")
