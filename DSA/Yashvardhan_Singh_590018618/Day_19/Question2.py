class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


# Create Linked List
values = [1, 2, 3, 4, 5]

head = Node(values[0])
temp = head

for i in range(1, len(values)):
    temp.next = Node(values[i])
    temp = temp.next


# Find Middle Node
slow = head
fast = head

while fast and fast.next:
    slow = slow.next
    fast = fast.next.next

print(slow.data)