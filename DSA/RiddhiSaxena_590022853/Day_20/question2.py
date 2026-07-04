class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


# Function to rearrange the linked list
def rearrangeEvenOdd(head):
    if head is None:
        return None

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

    # If no even or no odd nodes exist
    if evenStart is None:
        return oddStart
    if oddStart is None:
        return evenStart

    # Join even and odd lists
    evenEnd.next = oddStart

    return evenStart


# Function to print the linked list
def printList(head):
    current = head
    while current:
        print(current.data, end=" ")
        current = current.next
    print()


# Example usage
head = Node(17)
head.next = Node(15)
head.next.next = Node(8)
head.next.next.next = Node(12)
head.next.next.next.next = Node(10)
head.next.next.next.next.next = Node(5)
head.next.next.next.next.next.next = Node(4)

print("Original Linked List:")
printList(head)

head = rearrangeEvenOdd(head)

print("Modified Linked List:")
printList(head)