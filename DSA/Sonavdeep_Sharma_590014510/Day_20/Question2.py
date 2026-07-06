class ListNode:
    def __init__(self, val=0):
        self.val = val
        self.next = None

n = int(input())
arr = list(map(int, input().split()))

head = None
tail = None

for x in arr:
    node = ListNode(x)
    if head is None:
        head = node
        tail = node
    else:
        tail.next = node
        tail = node

even_head = even_tail = None
odd_head = odd_tail = None

current = head

while current:
    nxt = current.next
    current.next = None

    if current.val % 2 == 0:
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

    current = nxt

if even_head is None:
    head = odd_head
elif odd_head is None:
    head = even_head
else:
    even_tail.next = odd_head
    head = even_head

current = head

while current:
    print(current.val, end=" ")
    current = current.next