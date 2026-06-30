class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None


def deleteLast(head):
    # Empty list
    if head is None:
        return None

    # Only one node
    if head.next is None:
        return None

    temp = head

    # Move to the last node
    while temp.next:
        temp = temp.next

    # Remove the last node
    temp.prev.next = None

    return head


def printList(head):
    temp = head
    while temp:
        print(temp.data, end=" ")
        temp = temp.next
    print()


# Example
head = Node(1)
second = Node(2)
third = Node(3)
fourth = Node(4)

head.next = second
second.prev = head
second.next = third
third.prev = second
third.next = fourth
fourth.prev = third

head = deleteLast(head)
printList(head)
