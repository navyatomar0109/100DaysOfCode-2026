class Solution:
    def moveZeroes(self, nums: List[int]) -> None:

        count = 0
        for i in nums[::-1]:
            if i == 0:
                count += 1
                nums.remove(i)
        
        for i in range(count):
            nums.append(0)