class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

head = Node(1)
head.next = Node(2)
head.next.next = Node(3)
head.next.next.next = Node(4)
head.next.next.next.next = Node(5)

n = 2

dummy = Node(0)
dummy.next = head

fast = dummy
slow = dummy

for i in range(n + 1):
    fast = fast.next

while fast:
    fast = fast.next
    slow = slow.next

slow.next = slow.next.next

head = dummy.next

temp = head
while temp:
    print(temp.data, end=" ")
    temp = temp.next