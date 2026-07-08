'''Happy Number
Explanation
Given a positive integer n, repeatedly replace it with the sum of the squares of its digits. If the process eventually reaches 1, return true; otherwise, if it enters a cycle and never reaches 1, return false.'''

class Solution(object):
    def isHappy(self, n):
        
        visited = set()

        while n != 1 and n not in visited:
            visited.add(n)

            total = 0
            while n > 0:
                digit = n % 10
                total += digit * digit
                n //= 10

            n = total

        return n == 1