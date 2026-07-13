# Reverse a String Using Stack

s = input("Enter a string: ")

stack = []

# Push each character onto the stack
for ch in s:
    stack.append(ch)

# Pop characters to form the reversed string
reversed_string = ""

while stack:
    reversed_string += stack.pop()

print("Reversed string:", reversed_string)
