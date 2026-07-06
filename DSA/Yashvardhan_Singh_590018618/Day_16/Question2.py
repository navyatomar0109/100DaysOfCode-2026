class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None


def delete_last(head):

    if head is None:
        return None

    if head.next is None:
        return None

    temp = head

    while temp.next:
        temp = temp.next

    temp.prev.next = None

    return head


def print_list(head):
    while head:
        print(head.data, end="")
        if head.next:
            print(" <-> ", end="")
        head = head.next



head = Node(1)
node2 = Node(2)
node3 = Node(3)
node4 = Node(4)

head.next = node2

node2.prev = head
node2.next = node3

node3.prev = node2
node3.next = node4

node4.prev = node3


head = delete_last(head)

print_list(head)