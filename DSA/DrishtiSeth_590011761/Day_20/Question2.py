class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


def segregateEvenOdd(head):

    if head is None:
        return head

    evenStart = None
    evenEnd = None

    oddStart = None
    oddEnd = None

    current = head

    while current:

        if current.data % 2 == 0:

            if evenStart is None:
                evenStart = current
                evenEnd = evenStart

            else:
                evenEnd.next = current
                evenEnd = evenEnd.next

        else:

            if oddStart is None:
                oddStart = current
                oddEnd = oddStart

            else:
                oddEnd.next = current
                oddEnd = oddEnd.next

        current = current.next

    if evenStart is None:
        oddEnd.next = None
        return oddStart

    evenEnd.next = oddStart

    if oddEnd:
        oddEnd.next = None

    return evenStart
