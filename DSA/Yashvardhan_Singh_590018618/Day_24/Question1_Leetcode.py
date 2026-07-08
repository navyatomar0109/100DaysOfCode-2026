class Solution:
    def isHappy(self, n: int) -> bool:
        num = list()
        new = str(n)
        if n == 1 or n == 7:
            return True
        elif n < 10:
            return False
        else:
            while True:
                for i in new:
                    num.append(int(i))
                new = 0
                for i in num:
                    new += i * i
                return self.isHappy(new)
                

            
            