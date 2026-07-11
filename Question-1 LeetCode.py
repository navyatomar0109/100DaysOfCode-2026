class Solution(object):
    def compress(self, chars):
        write = 0
        i = 0

        while i < len(chars):
            ch = chars[i]
            count = 0

            
            while i < len(chars) and chars[i] == ch:
                i += 1
                count += 1

            # Write the character
            chars[write] = ch
            write += 1

            
            if count > 1:
                for digit in str(count):
                    chars[write] = digit
                    write += 1

        return write
