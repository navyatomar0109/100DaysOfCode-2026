def betterstring(s1, s2):


    def countdistinctsubsequences(s):
        dp = [0] * (len(s) + 1)
        dp[0] = 1
        last_seen = {}

        for i in range(1, len(s) + 1):
            char = s[i - 1]
            dp[i] = dp[i - 1] * 2
            
            if char in last_seen:
                dp[i] -= dp[last_seen[char]]
            
            last_seen[char] = i - 1
        
        return dp[len(s)]
    
    if countdistinctsubsequences(s1) > countdistinctsubsequences(s2):
        return s1
    elif countdistinctsubsequences(s1) < countdistinctsubsequences(s2):
        return s2
    else:
        return s1

'''
s1 = "abc"
s2 = "aac"
result = betterstring(s1, s2)
print(f"The better string is: {result}")
'''