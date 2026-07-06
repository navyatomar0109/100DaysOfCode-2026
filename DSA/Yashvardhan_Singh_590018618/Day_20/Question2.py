class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

values = [17, 15, 8, 9, 2, 4, 6]
head = Node(values[0])
current = head
for value in values[1:]:
    current.next = Node(value)
    current = current.next


def segregate_even_odd(head):
    if head is None:
        return head

    even_start = even_end = None
    odd_start = odd_end = None
    current = head

    while current:
        next_node = current.next

        if current.data % 2 == 0:
            if even_start is None:
                even_start = even_end = current
            else:
                even_end.next = current
                even_end = current
        else:
            if odd_start is None:
                odd_start = odd_end = current
            else:
                odd_end.next = current
                odd_end = current

        current = next_node

    if even_start is None or odd_start is None:
        return head

    even_end.next = odd_start
    odd_end.next = None

    return even_start

def print_list(head):
    while head:
        print(head.data, end="")
        if head.next:
            print(" -> ", end="")
        head = head.next
    print()
    
head = segregate_even_odd(head)
print_list(head)