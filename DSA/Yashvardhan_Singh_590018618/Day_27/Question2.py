arr = [3, 1, 6, 4]
l = 3
r = 6

def num_subarray_bounded_max(arr, l, r):
    total_subarrays = 0
    last_invalid = -1
    last_valid = -1
    
    for i, num in enumerate(arr):
        if num > r:
            last_invalid = i
        elif num >= l:
            last_valid = i
            
        if last_valid > last_invalid:
            total_subarrays += (last_valid - last_invalid)
            
    return total_subarrays

print(num_subarray_bounded_max(arr, l, r))