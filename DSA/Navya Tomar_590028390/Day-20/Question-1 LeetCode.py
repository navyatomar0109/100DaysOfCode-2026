class Solution(object):
    def removeElements(self, head, val):
        self.val = val
        self.next = next

class Solution:
    def removeElements(self, head, val):

        dummy = ListNode(0)
        dummy.next = head

        current = dummy

        while current.next:

            if current.next.val == val:
                current.next = current.next.next
            else:
                current = current.next

        return dummy.next
        """
        :type head: Optional[ListNode]
        :type val: int
        :rtype: Optional[ListNode]
        """
        
