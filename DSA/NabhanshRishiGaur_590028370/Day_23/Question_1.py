class Solution:
    def findContentChildren(self, g, s):
        g.sort()
        s.sort()

        i = j = 0
        satisfied = 0

        while i < len(g) and j < len(s):
            if s[j] >= g[i]:
                satisfied += 1
                i += 1
            j += 1

        return satisfied
