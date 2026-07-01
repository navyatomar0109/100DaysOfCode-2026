class Node:
    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None

n = int(input("Enter the number of nodes: "))
elements = list(map(int, input("Enter the elements of the doubly linked list: ").split()))

head = None
tail = None

for element in elements:
    new_node = Node(element)
    if head is None:
        head = new_node
        tail = new_node
    else:
        tail.next = new_node
        new_node.prev = tail
        tail = new_node

if head is None:
    print("NULL")
elif head.next is None:
    head = None
    print("NULL")
else:
    temp = head
    while temp.next:
        temp = temp.next
    temp.prev.next = None

    temp = head
    while temp:
        print(temp.data, end="")
        if temp.next:
            print(" <-> ", end="")
        temp = temp.next