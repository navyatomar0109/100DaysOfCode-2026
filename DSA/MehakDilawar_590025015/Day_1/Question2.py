#Write an efficient function to calculate the sum of all elements in an integer array.
#Input: [3, 8, 2, 9, 1]. Output: 23.
def sum_array(list_integer):
  return sum(list_integer)
list_integer=[]
n=int(input("Enter number of elements: "))
for i in range(n):
      x=int(input("Enter element: "))
      list_integer.append(x)
print(sum_array(list_integer))