class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return head

        curr = head
        net = curr.next

        while curr and net:
            if curr.val == net.val:
                curr.next = net.next
                net = curr.next
            else:
                curr = curr.next
                net = curr.next

        return head