class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


def reverseList(head):
    prev = None
    curr = head

    while curr:
        next_node = curr.next
        curr.next = prev
        prev = curr
        curr = next_node

    return prev


def printList(head):
    while head:
        print(head.data, end=" ")
        head = head.next
    print()


head = Node(1)
current = head
for i in range(2, 6):
    current.next = Node(i)
    current = current.next 

print("Original Linked List:")
printList(head)

# Reverse the linked list
head = reverseList(head)

print("Reversed Linked List:")
printList(head)
