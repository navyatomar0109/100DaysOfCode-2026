class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# Insert at the end
def insert_end(head, data):
    new_node = Node(data)

    if head is None:
        return new_node

    temp = head
    while temp.next:
        temp = temp.next

    temp.next = new_node
    return head

# Find the middle node
def middle_node(head):
    slow = head
    fast = head

    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next

    return slow

# Main
head = None
n = int(input("Enter number of nodes: "))

print("Enter node values:")
for _ in range(n):
    value = int(input())
    head = insert_end(head, value)

middle = middle_node(head)
print("Middle node:", middle.data)