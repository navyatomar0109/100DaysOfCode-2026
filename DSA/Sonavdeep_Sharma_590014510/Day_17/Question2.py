class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
def hasCycle(head):
    if head is None:
        return False

    slow = head
    fast = head

    while fast is not None and fast.next is not None:
        slow = slow.next
        fast = fast.next.next

        if slow == fast:
            return True

    return False

head = Node(3)
second = Node(2)
third = Node(0)
fourth = Node(-4)

head.next = second
second.next = third
third.next = fourth
fourth.next = second

print(hasCycle(head))