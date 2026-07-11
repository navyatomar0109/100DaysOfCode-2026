#Leetcode Problem 443
# String Compression

class Solution(object):
    def compress(self, chars):
        i = 0
        k = 0

        while i < len(chars):
            temp = chars[i]
            count = 0

            while i < len(chars) and chars[i] == temp:
                count += 1
                i += 1
            chars[k] = temp
            k += 1

            if count > 1:
                for digit in str(count):
                    chars[k] = digit
                    k += 1
        return k