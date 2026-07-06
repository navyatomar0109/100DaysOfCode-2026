class Solution:
    def betterString(self, s1, s2):
        def countDistinctSubsequences(s):
            dp = [0] * (len(s) + 1)
            dp[0] = 1
            last = {}

            for i in range(1, len(s) + 1):
                dp[i] = 2 * dp[i - 1]

                if s[i - 1] in last:
                    dp[i] -= dp[last[s[i - 1]] - 1]

                last[s[i - 1]] = i

            return dp[len(s)]

        if countDistinctSubsequences(s1) >= countDistinctSubsequences(s2):
            return s1
        else:
            return s2