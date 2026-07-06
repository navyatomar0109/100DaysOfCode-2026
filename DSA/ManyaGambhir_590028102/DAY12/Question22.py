class Solution:
    def findSubString(self, s):
        distinct = len(set(s))
        freq = {}
        start = 0
        count = 0
        min_len = len(s)

        for end in range(len(s)):
            ch = s[end]
            freq[ch] = freq.get(ch, 0) + 1

            if freq[ch] == 1:
                count += 1

            while count == distinct:
                min_len = min(min_len, end - start + 1)

                freq[s[start]] -= 1
                if freq[s[start]] == 0:
                    count -= 1
                start += 1

        return min_len