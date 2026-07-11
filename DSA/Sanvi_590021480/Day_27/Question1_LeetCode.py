class Solution:
    def compress(self, chars: List[str]) -> int:
        write=0
        read=0
        while read<len(chars):
            ch=chars[read]
            count=0

            while read<len(chars) and chars[read]==ch:
                read+=1
                count+=1
            chars[write]=ch
            write+=1
            if count>1:
                for dig in str(count):
                    chars[write]=dig
                    write+=1
        return write
