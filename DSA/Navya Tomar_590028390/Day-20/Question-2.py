class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


def segregateEvenOdd(head):

    if head is None:
        return None

    # Heads and tails of even and odd lists
    evenStart = evenEnd = None
    oddStart = oddEnd = None

    curr = head

    while curr:

        nextNode = curr.next      # Save next node
        curr.next = None          # Disconnect current node

        #  if current node is even
        if curr.data % 2 == 0:

            # First even node
            if evenStart is None:
                evenStart = evenEnd = curr

            # Add to end of even list
            else:
                evenEnd.next = curr
                evenEnd = curr

        # Current node is odd
        else:

            # First odd node
            if oddStart is None:
                oddStart = oddEnd = curr

            # Add to end of odd list
            else:
                oddEnd.next = curr
                oddEnd = curr

        curr = nextNode

    # If no even nodes
    if evenStart is None:
        return oddStart

    # If no odd nodes
    if oddStart is None:
        return evenStart

    # join even list with odd list
    evenEnd.next = oddStart

    return evenStart


def printList(head):
    while head:
        print(head.data, end=" ")
        head = head.next




n = int(input())
arr = list(map(int, input().split()))

head = tail = None

for x in arr:
    node = Node(x)
    if head is None:
        head = tail = node
    else:
        tail.next = node
        tail = node

head = segregateEvenOdd(head)

printList(head)
