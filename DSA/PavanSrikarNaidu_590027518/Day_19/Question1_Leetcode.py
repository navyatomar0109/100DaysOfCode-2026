class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def deleteDuplicates(self, head):
        current = head

        while current and current.next:
            if current.val == current.next.val:
                current.next = current.next.next
            else:
                current = current.next

        return head


# Function to create linked list
def createLinkedList(arr):
    if not arr:
        return None

    head = ListNode(arr[0])
    current = head

    for value in arr[1:]:
        current.next = ListNode(value)
        current = current.next

    return head


# Function to print linked list
def printLinkedList(head):
    result = []

    while head:
        result.append(head.val)
        head = head.next

    print(result)


# Test Cases
arr = [1, 1, 2]
head = createLinkedList(arr)

solution = Solution()
newHead = solution.deleteDuplicates(head)

print("Output:")
printLinkedList(newHead)


# Another Test
arr = [1, 1, 2, 3, 3]
head = createLinkedList(arr)

newHead = solution.deleteDuplicates(head)

print("Output:")
printLinkedList(newHead)