def squares(nums):
    l = 0
    r = len(nums) - 1
    pos = len(nums) - 1
    result = [0] * len(nums)
    while l<r:
        l_rr = nums[l] ** 2
        r_rr = nums[r] ** 2
        if abs(l_rr) > abs(r_rr):
            result[pos] = l_rr
            l += 1         
        else:
            result[pos] = r_rr
            r -= 1
        pos -= 1
    return result



nums = [-4,-1,0,3,10]
print(squares(nums))