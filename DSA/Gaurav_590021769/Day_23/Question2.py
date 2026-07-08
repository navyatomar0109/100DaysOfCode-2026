class Solution(object):
    def backspaceCompare(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """

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