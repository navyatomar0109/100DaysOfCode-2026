class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


def findMiddle(head):
    if head is None:
        return None

    slow = head
    fast = head

    while fast is not None and fast.next is not None:
        slow = slow.next
        fast = fast.next.next

    return slow


def printList(head):
    temp = head
    while temp:
        print(temp.data, end=" -> ")
        temp = temp.next
    print("NULL")


# Driver Code
head = Node(10)
head.next = Node(20)
head.next.next = Node(30)
head.next.next.next = Node(40)
head.next.next.next.next = Node(50)
head.next.next.next.next.next = Node(60)

print("Linked List:")
printList(head)

middle = findMiddle(head)

if middle is not None:
    print("Middle Node:", middle.data)
else:
    print("The list is empty.")