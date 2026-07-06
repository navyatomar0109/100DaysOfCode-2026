# Segregate Even and Odd Nodes in a Linked List

class ListNode:
    def __init__(self, val):
        self.val = val
        self.next = None


def createLinkedList(arr):
    if not arr:
        return None

    head = ListNode(arr[0])
    current = head

    for value in arr[1:]:
        current.next = ListNode(value)
        current = current.next

    return head


def segregateEvenOdd(head):
    if head is None:
        return None

    evenHead = evenTail = None
    oddHead = oddTail = None

    current = head

    while current:
        nextNode = current.next
        current.next = None

        if current.val % 2 == 0:
            if evenHead is None:
                evenHead = evenTail = current
            else:
                evenTail.next = current
                evenTail = current
        else:
            if oddHead is None:
                oddHead = oddTail = current
            else:
                oddTail.next = current
                oddTail = current

        current = nextNode

    if evenHead is None:
        return oddHead

    evenTail.next = oddHead

    return evenHead


def printLinkedList(head):
    while head:
        print(head.val, end="")
        if head.next:
            print(" -> ", end="")
        head = head.next
    print()


n = int(input("Enter number of nodes: "))

arr = list(map(int, input("Enter node values: ").split()))

head = createLinkedList(arr)

print("\nOriginal Linked List:")
printLinkedList(head)

head = segregateEvenOdd(head)

print("Linked List after Segregating Even and Odd Nodes:")
printLinkedList(head)