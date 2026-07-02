class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


def removeNthFromEnd(head, n):
    dummy = Node(0)
    dummy.next = head

    fast = slow = dummy

    for _ in range(n + 1):
        if fast:
            fast = fast.next

    while fast:
        fast = fast.next
        slow = slow.next

    slow.next = slow.next.next

    return dummy.next


def printList(head):
    while head:
        print(head.data, end=" ")
        head = head.next
    print()



values = list(map(int, input("Enter linked list elements: ").split()))
n = int(input("Enter n: "))

head = None
tail = None

for value in values:
    new_node = Node(value)
    if head is None:
        head = new_node
        tail = new_node
    else:
        tail.next = new_node
        tail = new_node

head = removeNthFromEnd(head, n)

print("Updated Linked List:")
printList(head)
