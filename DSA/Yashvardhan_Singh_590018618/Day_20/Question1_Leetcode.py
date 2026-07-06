class Solution:
    def removeElements(self, head, val):

        dummy = ListNode(0)
        dummy.next = head

        temp = dummy

        while temp.next:

            if temp.next.val == val:
                temp.next = temp.next.next
            else:
                temp = temp.next

        return dummy.next