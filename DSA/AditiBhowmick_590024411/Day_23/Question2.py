def process_string(s):
    result = []

    for ch in s:
        if ch == "#":
            if result:
                result.pop()
        else:
            result.append(ch)

    return "".join(result)

# User Input
s = input("Enter first string: ")
t = input("Enter second string: ")

if process_string(s) == process_string(t):
    print("true")
else:
    print("false")