class Solution:
    def removeDuplicates(self, s):
        ans = ""

        for ch in s:
            if ans and ans[-1] == ch:
                ans = ans[:-1]
            else:
                ans += ch

        return ans
