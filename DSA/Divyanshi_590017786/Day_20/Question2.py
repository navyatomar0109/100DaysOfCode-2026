class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


def segregate_even_odd(head):
    if head is None:
        return None

    even_head = even_tail = None
    odd_head = odd_tail = None

    current = head

    while current:
        next_node = current.next
        current.next = None

        if current.data % 2 == 0:
            if even_head is None:
                even_head = even_tail = current
            else:
                even_tail.next = current
                even_tail = current
        else:
            if odd_head is None:
                odd_head = odd_tail = current
            else:
                odd_tail.next = current
                odd_tail = current

        current = next_node

    if even_head is None:
        return odd_head

    even_tail.next = odd_head
    return even_head


def print_list(head):
    while head:
        print(head.data, end="")
        if head.next:
            print(" -> ", end="")
        head = head.next
    print()


# Input
n = int(input("Enter number of nodes: "))
values = list(map(int, input("Enter node values: ").split()))

head = None
tail = None

for value in values:
    new_node = Node(value)
    if head is None:
        head = tail = new_node
    else:
        tail.next = new_node
        tail = new_node

head = segregate_even_odd(head)

print("Modified Linked List:")
print_list(head)
