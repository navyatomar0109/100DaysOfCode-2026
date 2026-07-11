arr=list(map(int, input("Enter array: ").split()))
l=int(input("Enter l: "))
r=int(input("Enter r: "))
count=0
for i in range(len(arr)):
  for j in range(i,len(arr)):
    x=arr[i:j+1]
    m=max(x)
    if l<=m<=r:
      count+=1
print(count)
