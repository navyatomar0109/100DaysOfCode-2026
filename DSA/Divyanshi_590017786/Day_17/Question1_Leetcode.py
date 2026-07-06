# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reverse(self, head):
        prev = None

        while head:
            nxt = head.next
            head.next = prev
            prev = head
            head = nxt

        return prev

    def isPalindrome(self, head):
        if not head or not head.next:
            return True

        # Find the middle
        slow = fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        # Reverse second half
        second = self.reverse(slow)
        copy = second  # Save to restore later

        # Compare both halves
        first = head
        palindrome = True

        while second:
            if first.val != second.val:
                palindrome = False
                break
            first = first.next
            second = second.next

        # Restore original list
        self.reverse(copy)

        return palindrome