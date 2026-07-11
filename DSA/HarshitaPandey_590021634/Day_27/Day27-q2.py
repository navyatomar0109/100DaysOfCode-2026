def compress(self, chars):
        
    count=0
    s = ''

    for i in range(len(chars)):
        if i ==0 or chars[i] != chars[i-1]:
            if i != 0:
                if count > 1:
                    s += str(count)
                    s += chars[i]
                    count = 1
                

        else:
            count += 1
            
    if count > 1:
        s += str(count)

    for i in range(len(s)):
        chars[i] = s[i]

    del chars[len(s): ]
    return len(chars)