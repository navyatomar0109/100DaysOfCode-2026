class Solution(object):
    def removeNthFromEnd(self, head, n):
        dummy = ListNode(0) # type: ignore
        dummy.next = head

        fast = slow = dummy

        # Move fast pointer n+1 steps ahead
        for _ in range(n + 1):
            fast = fast.next

        # Move both pointers
        while fast:
            fast = fast.next
            slow = slow.next

        # Remove the nth node from the end
        slow.next = slow.next.next

        return dummy.next