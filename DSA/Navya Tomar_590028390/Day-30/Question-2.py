def insertAtBottom(stack, x):
    
    if not stack:
        stack.append(x)
        return

    # Remove the top element
    temp = stack.pop()

    
    insertAtBottom(stack, x)

   
    stack.append(temp)



stack = list(map(int, input().split()))
x = int(input())

insertAtBottom(stack, x)

print(stack)
