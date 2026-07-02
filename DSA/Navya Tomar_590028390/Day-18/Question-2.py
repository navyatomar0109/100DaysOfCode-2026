class ListNode:
    def __init__(self, val=0):
        self.val = val
        self.next = None


def removeNthFromEnd(head, n):
    dummy = ListNode(0)
    dummy.next = head

    fast = dummy
    slow = dummy

    for i in range(n + 1):
        fast = fast.next

    while fast:
        fast = fast.next
        slow = slow.next

    slow.next = slow.next.next

    return dummy.next


def createList(arr):
    if not arr:
        return None

    head = ListNode(arr[0])
    temp = head

    for i in range(1, len(arr)):
        temp.next = ListNode(arr[i])
        temp = temp.next

    return head


def printList(head):
    while head:
        print(head.val, end=" ")
        head = head.next


arr = [1, 2, 3, 4, 5]
n = 2

head = createList(arr)
head = removeNthFromEnd(head, n)
printList(head)
