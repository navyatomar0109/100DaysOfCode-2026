st = [1, 2, 3, 4]

temp = []
copy = []

# Move all elements from st to temp
while st:
    temp.append(st.pop())

# Move elements from temp back to st and to copy
while temp:
    x = temp.pop()
    st.append(x)
    copy.append(x)

print(copy)
