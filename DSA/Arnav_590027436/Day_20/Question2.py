def sortevenodd(head):
    
    if head is None:
        return None
    
    curr = head
    even_head = even_tail = None
    odd_head = odd_tail = None

    while curr:
        
        nxt_node = curr.next
        
        if curr.val % 2 == 0:
            if even_head is None:
                even_head = even_tail = curr
        
            else:
                even_tail.next = curr
                even_tail = even_tail.next
        
        else:
            if odd_head is None:
                odd_head = odd_tail = curr
        
            else:
                odd_tail.next = curr
                odd_tail = odd_tail.next
        
        curr = nxt_node
    
    if even_tail:
        even_tail.next = odd_head
        
    if odd_tail:
        odd_tail.next = None
        
    if even_head is None:
        return odd_head
        
    return even_head