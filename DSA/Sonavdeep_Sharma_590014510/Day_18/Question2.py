class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def removeNthFromEnd(self, head, n):
        dummy = ListNode(0)
        dummy.next = head

        fast = dummy
        slow = dummy

        for _ in range(n + 1):
            fast = fast.next

        while fast:
            fast = fast.next
            slow = slow.next

        slow.next = slow.next.next

        return dummy.next


def createLinkedList(values):
    dummy = ListNode()
    current = dummy

    for value in values:
        current.next = ListNode(value)
        current = current.next

    return dummy.next


def printLinkedList(head):
    while head:
        print(head.val, end=" ")
        head = head.next
    print()


size = int(input("Enter number of nodes: "))
values = list(map(int, input("Enter node values: ").split()))
n = int(input("Enter n: "))

head = createLinkedList(values)

solution = Solution()
head = solution.removeNthFromEnd(head, n)

print("Updated Linked List:")
printLinkedList(head)