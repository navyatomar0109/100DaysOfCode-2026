class Solution:
    def segregateEvenOdd(self, head):
        even_dummy = ListNode(0)
        odd_dummy = ListNode(0)
        
        even = even_dummy
        odd = odd_dummy
        
        current = head
        
        while current:
            if current.val % 2 == 0:
                even.next = current
                even = even.next
            else:
                odd.next = current
                odd = odd.next
            current = current.next
        
        odd.next = None
        even.next = odd_dummy.next
        
        return even_dummy.next