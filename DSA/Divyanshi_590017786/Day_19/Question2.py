class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


def find_middle(head):
    slow = head
    fast = head

    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next

    return slow



arr = list(map(int, input().split()))

head = Node(arr[0])
current = head

for num in arr[1:]:
    current.next = Node(num)
    current = current.next

middle = find_middle(head)

print(middle.data)

