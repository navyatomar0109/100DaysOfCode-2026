class Solution:
    def triangleNumber(self, nums: List[int]) -> int:
        nums.sort()
        countt=0
        for i in range(len(nums)-1,1,-1):
            l=0
            r=i-1
            while l<r:
                if nums[l]+nums[r]>nums[i]:
                    countt=countt+r-l
                    r=r-1
                else:
                    l=l+1
        return countt
