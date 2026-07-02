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

# Remove nth node from the end
def remove_nth_from_end(head, n):
    dummy = Node(0)
    dummy.next = head

    first = dummy
    second = dummy

    # Move first pointer n+1 steps ahead
    for _ in range(n + 1):
        first = first.next

    # Move both pointers
    while first:
        first = first.next
        second = second.next

    # Delete the nth node
    second.next = second.next.next

    return dummy.next

# Display the linked list
def display(head):
    print("[", end="")
    while head:
        print(head.data, end="")
        if head.next:
            print(",", end="")
        head = head.next
    print("]")

# Main
head = None
size = int(input("Enter number of nodes: "))

print("Enter node values:")
for _ in range(size):
    value = int(input())
    head = insert_end(head, value)

n = int(input("Enter n: "))

head = remove_nth_from_end(head, n)

print("Updated Linked List:")
display(head)