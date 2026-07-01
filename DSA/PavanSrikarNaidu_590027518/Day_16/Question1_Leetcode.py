class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def swapPairs(head):
    dummy = ListNode(0)
    dummy.next = head
    prev = dummy

    while prev.next and prev.next.next:
        first = prev.next
        second = first.next

        # Swap nodes
        first.next = second.next
        second.next = first
        prev.next = second

        prev = first

    return dummy.next


def createLinkedList(arr):
    dummy = ListNode()
    current = dummy

    for num in arr:
        current.next = ListNode(num)
        current = current.next

    return dummy.next


def printLinkedList(head):
    while head:
        print(head.val, end=" -> " if head.next else "")
        head = head.next
    print()


# Driver Code
arr = [1, 2, 3, 4]

head = createLinkedList(arr)

print("Original Linked List:")
printLinkedList(head)

head = swapPairs(head)

print("After Swapping:")
printLinkedList(head)