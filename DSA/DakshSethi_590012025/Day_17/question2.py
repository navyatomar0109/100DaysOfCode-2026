class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class Solution:
    def detectLoop(self, head):
        slow = head
        fast = head

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

            if slow == fast:
                return True

        return False


# Creating Linked List: 3 -> 2 -> 0 -> -4
head = Node(3)
second = Node(2)
third = Node(0)
fourth = Node(-4)

head.next = second
second.next = third
third.next = fourth

# Creating a cycle
# Last node points to node with value 2
fourth.next = second

obj = Solution()

if obj.detectLoop(head):
    print("Cycle Detected")
else:
    print("No Cycle")