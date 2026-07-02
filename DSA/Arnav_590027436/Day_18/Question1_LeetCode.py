# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def rotateRight(self, head, k):
        if not head or not head.next:
            return head
        
        curr = head
        length = 1
        while curr.next:
            length += 1
            curr = curr.next
        
        curr.next = head
        k = k % length

        for _ in range(length - k) :
            curr = curr.next

        new_head = curr.next
        curr.next = None

        return new_head