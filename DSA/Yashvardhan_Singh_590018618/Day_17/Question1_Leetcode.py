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

        slow = fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        second = self.reverse(slow)
        copy = second 

        first = head
        palindrome = True

        while second:
            if first.val != second.val:
                palindrome = False
                break
            first = first.next
            second = second.next

        self.reverse(copy)

        return palindrome