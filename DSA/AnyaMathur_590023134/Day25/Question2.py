# Problem 2 
# Pair with Target Sum 

def pairWithTargetSum(numbers, target):
    left = 0
    right = len(numbers) - 1

    while left < right:
        currentSum = numbers[left] + numbers[right]
        if currentSum == target:
            return True
        elif currentSum < target:
            left += 1
        else:
            right -= 1
    return False

numbers = list(map(int, input("Enter the sorted list elements: ").split()))
target = int(input("Enter the target: "))

if pairWithTargetSum(numbers, target):
    print("True")
else:
    print("False")