class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Solution(object):
    def hasCycle(self, head):
        slow = head
        fast = head

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

            if slow == fast:
                return True

        return False


arr = list(map(int, input("Enter linked list elements: ").split()))

# Position where last node points -1 for no cycle
pos = int(input("Enter position for cycle (-1 for no cycle): "))

# Create linked list
head = Node(arr[0])
curr = head
nodes = [head]

for x in arr[1:]:
    new_node = Node(x)
    curr.next = new_node
    curr = new_node
    nodes.append(new_node)

if pos != -1:
    curr.next = nodes[pos]

# Check cycle
obj = Solution()
print(obj.hasCycle(head))
