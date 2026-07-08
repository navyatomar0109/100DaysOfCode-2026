def build(string):
    stack = []

    for ch in string:
        if ch == '#':
            if stack:
                stack.pop()
        else:
            stack.append(ch)

    return stack

s = input("Enter first string: ")
t = input("Enter second string: ")

if build(s) == build(t):
    print(True)#
else:
    print(False)