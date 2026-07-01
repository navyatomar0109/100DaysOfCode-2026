class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def has_cycle(head):
    slow = head
    fast = head

    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next

        if slow == fast:
            return True

    return False

# User Input
n = int(input("Enter number of nodes: "))

nodes = []

print("Enter node values:")
for _ in range(n):
    value = int(input())
    nodes.append(Node(value))

# Connect nodes
for i in range(n - 1):
    nodes[i].next = nodes[i + 1]

pos = int(input("Enter position to create cycle (-1 for no cycle): "))

if pos != -1:
    nodes[-1].next = nodes[pos]

head = nodes[0] if n > 0 else None

if has_cycle(head):
    print("true")
else:
    print("false")