class Solution:
    def deleteLastNode(self, head):
        if head is None:
            return None


        if head.next is None:
            return None

        temp = head

        while temp.next:
            temp = temp.next

        temp.prev.next = None

        return head