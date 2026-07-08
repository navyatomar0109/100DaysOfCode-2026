#Process both strings by treating # as a backspace and return true if the resulting strings are identical; 
#otherwise, return false.
#Input:s = "ab#c", t = "ad#c". Output:true

def Compare(s, t):
    def process(string):
        stack = []
        for ch in string:
            if ch == '#':
                if stack:
                    stack.pop()
            else:
                stack.append(ch)
        return "".join(stack)

    return process(s) == process(t)

s=input("Enter string 1: ")
t=input("Enter string 2: ")
Compare(s, t)