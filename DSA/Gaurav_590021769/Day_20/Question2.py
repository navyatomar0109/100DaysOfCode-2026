# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution(object):
    def segregateEvenOdd(self, head):
        if not head or not head.next:
            return head

        evenHead = evenTail = None
        oddHead = oddTail = None

        current = head

        while current:
            nextNode = current.next
            current.next = None

            if current.val % 2 == 0:
                if evenHead is None:
                    evenHead = evenTail = current
                else:
                    evenTail.next = current
                    evenTail = current
            else:
                if oddHead is None:
                    oddHead = oddTail = current
                else:
                    oddTail.next = current
                    oddTail = current

            current = nextNode

        if evenHead is None:
            return oddHead

        evenTail.next = oddHead

        return evenHead