def removeNthFromEnd(head, n):
    length = 0
    curr = head
    while curr:
        length += 1
        curr = curr.next
        
    if length == n:
        return head.next
        
    curr = head
    for _ in range(length - n - 1):
        curr = curr.next
        
    curr.next = curr.next.next
    
    return head