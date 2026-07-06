from collections import Counter
import re

class Solution:
    def mostCommonWord(self, paragraph, banned):
        banned = set(banned)

        words = re.findall(r"[a-zA-Z]+", paragraph.lower())

        count = Counter()
        for word in words:
            if word not in banned:
                count[word] += 1

        return count.most_common(1)[0][0]