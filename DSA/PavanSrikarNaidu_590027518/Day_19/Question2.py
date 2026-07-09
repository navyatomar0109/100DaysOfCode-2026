class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def middleNode(self, head):
        slow = head
        fast = head

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        return slow



# Create Linked List
def createLinkedList(arr):
    if not arr:
        return None

    head = ListNode(arr[0])
    current = head

    for value in arr[1:]:
        current.next = ListNode(value)
        current = current.next

    return head


# Print Linked List
def printLinkedList(head):
    result = []

    while head:
        result.append(head.val)
        head = head.next

    print(result)


# Test Case 1
arr = [1, 2, 3, 4, 5]
head = createLinkedList(arr)

solution = Solution()
middle = solution.middleNode(head)

print("Middle to End:")
printLinkedList(middle)


# Test Case 2
arr = [1, 2, 3, 4, 5, 6]
head = createLinkedList(arr)

middle = solution.middleNode(head)

print("Middle to End:")
printLinkedList(middle)