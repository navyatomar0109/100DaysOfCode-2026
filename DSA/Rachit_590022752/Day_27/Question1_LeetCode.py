class Solution:
    def compress(self, chars: List[str]) -> int:
        """
        :type chars: List[str]
        :rtype: int
        """
        s = ""
        curr = chars[0]
        count = 0

        for ch in chars:
            if ch == curr:
                count += 1
            else:
                if count == 1:
                    s += curr
                else:
                    s += (curr + str(count))
                count = 1
                curr = ch

        if count == 1:
            s += curr
        else:
            s += (curr + str(count))
        result = list(s)
        print(result)
        for i in range(len(result)):
            chars[i] = result[i]
        return len(result)
