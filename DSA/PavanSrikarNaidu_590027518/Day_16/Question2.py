class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None


def deleteLast(head):
    # If the list is empty
    if head is None:
        return None

    # If there is only one node
    if head.next is None:
        return None

    # Traverse to the last node
    temp = head
    while temp.next:
        temp = temp.next

    # Remove the last node
    temp.prev.next = None

    return head


def printList(head):
    if head is None:
        print("NULL")
        return

    temp = head
    while temp:
        print(temp.data, end="")
        if temp.next:
            print(" <-> ", end="")
        temp = temp.next
    print()


# Driver Code
arr = [1, 2, 3, 4]

head = None
tail = None

for num in arr:
    newNode = Node(num)
    if head is None:
        head = newNode
        tail = newNode
    else:
        tail.next = newNode
        newNode.prev = tail
        tail = newNode

head = deleteLast(head)

printList(head)