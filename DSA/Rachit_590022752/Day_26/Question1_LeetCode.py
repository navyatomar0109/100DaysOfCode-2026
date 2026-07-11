class Solution(object):
    def sortColors(self, nums):
        colors = []

        for i in nums:
            if i == 0:
                colors.append("red")
            elif i == 1:
                colors.append("white")
            else:
                colors.append("blue")

        index = 0

        for color in ["red", "white", "blue"]:
            for c in colors:
                if c == color:
                    if color == "red":
                        nums[index] = 0
                    elif color == "white":
                        nums[index] = 1
                    else:
                        nums[index] = 2
                    index += 1
