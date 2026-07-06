s = input()

vowels = "AEIOUYaeiouy"
result = ""

for ch in s:
    if ch not in vowels:
        result += "." + ch.lower()

print(result)