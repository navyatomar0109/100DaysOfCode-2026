# Detect Cycle in a Linked List

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


def hasCycle(head):
    slow = head
    fast = head

    while fast and fast.next:
        slow = slow.next         
        fast = fast.next.next    

        if slow == fast:
            return True

    return False


n = int(input("Enter number of nodes: "))

values = list(map(int, input("Enter node values: ").split()))

nodes = []

for value in values:
    nodes.append(Node(value))

for i in range(n - 1):
    nodes[i].next = nodes[i + 1]

pos = int(input("Enter position to create cycle (-1 for no cycle): "))

if pos != -1:
    nodes[-1].next = nodes[pos]

if hasCycle(nodes[0]):
    print("true")
else:
    print("false")