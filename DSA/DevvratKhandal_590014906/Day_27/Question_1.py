chars = input("Enter characters separated by space: ").split()

write = 0
read = 0

while read < len(chars):
    current = chars[read]
    count = 0

    while read < len(chars) and chars[read] == current:
        read += 1
        count += 1

    chars[write] = current
    write += 1

    if count > 1:
        for digit in str(count):
            chars[write] = digit
            write += 1

print("Length of compressed array =", write)
print("Compressed array =", chars[:write])