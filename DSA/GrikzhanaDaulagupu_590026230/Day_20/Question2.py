class Solution:
    def rearrangeEvenOdd(self, head):
        if not head or not head.next:
            return head

        evenHead = evenTail = None
        oddHead = oddTail = None

        curr = head

        while curr:
            nextNode = curr.next
            curr.next = None

            if curr.val % 2 == 0:
                if evenHead is None:
                    evenHead = evenTail = curr
                else:
                    evenTail.next = curr
                    evenTail = curr
            else:
                if oddHead is None:
                    oddHead = oddTail = curr
                else:
                    oddTail.next = curr
                    oddTail = curr

            curr = nextNode

        if evenHead is None:
            return oddHead

        evenTail.next = oddHead
        return evenHead
