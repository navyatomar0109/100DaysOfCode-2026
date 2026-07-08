def process(string):
    stack = []

    for ch in string:
        if ch == "#":
            if stack:
                stack.pop()
        else:
            stack.append(ch)

    return "".join(stack)


s = input()
t = input()

if process(s) == process(t):
    print(True)
else:
    print(False)