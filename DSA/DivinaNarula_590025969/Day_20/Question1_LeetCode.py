# Remove Linked List Elements

# Definition for singly-linked list
class ListNode:
    def __init__(self, val=0):
        self.val = val
        self.next = None


class Solution:
    def removeElements(self, head, val):
        dummy = ListNode(0)
        dummy.next = head

        prev = dummy
        curr = head

        while curr:
            if curr.val == val:
                prev.next = curr.next
            else:
                prev = curr
            curr = curr.next

        return dummy.next


# Function to create linked list
def createLinkedList(arr):
    if not arr:
        return None

    head = ListNode(arr[0])
    current = head

    for num in arr[1:]:
        current.next = ListNode(num)
        current = current.next

    return head


# Function to print linked list
def printLinkedList(head):
    if head is None:
        print("[]")
        return

    result = []
    while head:
        result.append(str(head.val))
        head = head.next

    print(" -> ".join(result))


n = int(input("Enter number of nodes: "))

if n == 0:
    arr = []
else:
    arr = list(map(int, input("Enter node values: ").split()))

val = int(input("Enter value to remove: "))

head = createLinkedList(arr)

sol = Solution()
head = sol.removeElements(head, val)

print("Updated Linked List:")
printLinkedList(head)