class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None

    # Insert a node at the end
    def insert(self, data):
        new_node = Node(data)

        if self.head is None:
            self.head = new_node
            return

        temp = self.head
        while temp.next:
            temp = temp.next

        temp.next = new_node

    # Remove nth node from the end
    def remove_nth_from_end(self, n):
        dummy = Node(0)
        dummy.next = self.head

        fast = dummy
        slow = dummy

        # Move fast pointer n+1 steps ahead
        for _ in range(n + 1):
            if fast is None:
                print("Invalid position")
                return
            fast = fast.next

        # Move both pointers
        while fast:
            fast = fast.next
            slow = slow.next

        # Delete the node
        if slow.next:
            slow.next = slow.next.next

        self.head = dummy.next

    # Display the linked list
    def display(self):
        if self.head is None:
            print("List is empty")
            return

        temp = self.head
        while temp:
            print(temp.data, end=" ")
            temp = temp.next
        print()


# Driver Code
ll = LinkedList()

n = int(input("Enter number of nodes: "))

print("Enter node values:")
for _ in range(n):
    value = int(input())
    ll.insert(value)

pos = int(input("Enter the position from the end to remove: "))

ll.remove_nth_from_end(pos)

print("Updated Linked List:")
ll.display()