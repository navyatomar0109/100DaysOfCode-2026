class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None


def deleteLastNode(head):
    if head is None:
        return None
    
    if head.next is None:        
        return None
    
    last = head
    while last.next:
        last = last.next
    
    last.prev.next = None        
    last.prev = None             
    
    return head


def printList(head):
    current = head
    result = []
    while current:
        result.append(str(current.data))
        current = current.next
    
    if not result:
        print("NULL")
    else:
        print(" <-> ".join(result))