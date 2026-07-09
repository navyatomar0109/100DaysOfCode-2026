l=[]
n=int(input("Enter size: "))
for i in range (n):
    a=int(input("Enter element: "))
    l.append(a)
for i in range (n):
    l[i]=l[i]**2
l.sort()    
print(f"Result: {l}")    
    
