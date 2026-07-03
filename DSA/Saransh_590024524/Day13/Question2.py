s1 = input("Enter the first string   : ").strip()
s2 = input("Enter the second string  : ").strip()

if len(set(s1)) == len(set(s2)):
    print(s1)
elif len(set(s1)) > len(set(s2)):
    print(s1)
else:
    print(s2)        