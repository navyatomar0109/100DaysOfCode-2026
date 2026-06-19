def equal_arr(arr1,arr2):
    if len(arr1) != len(arr2):
        return False
        
    return sorted(arr1) == sorted(arr2)


arr1 = [1,2,3,4]
arr2 = [4,3,2,10]
if equal_arr(arr1,arr2):
    print("true")
else:
    print("false")    