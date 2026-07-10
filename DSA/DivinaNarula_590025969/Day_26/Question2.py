# Triplet Sum Check

def triplet_sum_check(arr):
    arr.sort()
    n = len(arr)

    for i in range(n - 1, 1, -1):
        left = 0
        right = i - 1

        while left < right:
            current_sum = arr[left] + arr[right]

            if current_sum == arr[i]:
                return True
            elif current_sum < arr[i]:
                left += 1
            else:
                right -= 1

    return False

n = int(input("Enter the number of elements: "))
arr = list(map(int, input("Enter the elements: ").split()))

if len(arr) != n:
    print("Please enter exactly", n, "elements.")
else:
    if triplet_sum_check(arr):
        print("True")
    else:
        print("False")