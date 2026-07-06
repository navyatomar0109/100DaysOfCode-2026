class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None
def deleteLast(head):
    if head is None:
        return None
    if head.next is None:
        return None
    temp = head
    while temp.next:
        temp = temp.next
    temp.prev.next = None
    return head
def printList(head):
    while head:
        print(head.data, end=" ")
        head = head.next
head = Node(1)
head.next = Node(2)
head.next.prev = head
head.next.next = Node(3)
head.next.next.prev = head.next
head.next.next.next = Node(4)
head.next.next.next.prev = head.next.next
head = deleteLast(head)
printList(head)