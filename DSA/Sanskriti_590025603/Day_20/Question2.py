class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
def segregateEvenOdd(head):
    if head is None:
        return head
    evenStart = evenEnd = None
    oddStart = oddEnd = None
    current = head
    while current:
        nextNode = current.next
        current.next = None
        if current.data % 2 == 0:
            if evenStart is None:
                evenStart = evenEnd = current
            else:
                evenEnd.next = current
                evenEnd = current
        else:
            if oddStart is None:
                oddStart = oddEnd = current
            else:
                oddEnd.next = current
                oddEnd = current
        current = nextNode
    if evenStart is None:
        return oddStart
    evenEnd.next = oddStart
    return evenStart