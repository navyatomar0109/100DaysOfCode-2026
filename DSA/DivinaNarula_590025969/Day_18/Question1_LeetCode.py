# Rotate List

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: Optional[ListNode]
        :type k: int
        :rtype: Optional[ListNode]
        """

        if not head or not head.next or k == 0:
            return head

        length = 1
        last = head

        while last.next:
            last = last.next
            length += 1

        k = k % length

        if k == 0:
            return head

        last.next = head

        steps = length - k - 1
        new_tail = head

        for i in range(steps):
            new_tail = new_tail.next

        new_head = new_tail.next

        new_tail.next = None

        return new_head