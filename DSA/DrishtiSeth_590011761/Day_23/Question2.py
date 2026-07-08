class Solution:
    def backspaceCompare(self, s, t):
        def process(string):
            stack = []

            for ch in string:
                if ch == '#':
                    if stack:
                        stack.pop()
                else:
                    stack.append(ch)

            return ''.join(stack)

        return process(s) == process(t)
