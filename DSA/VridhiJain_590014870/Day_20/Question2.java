class Solution {
    public ListNode segregateEvenOdd(ListNode head) {
        ListNode evenHead = null;
        ListNode evenTail = null;
        ListNode oddHead = null;
        ListNode oddTail = null;
        ListNode current = head;
        while (current != null) {
            ListNode nextNode = current.next;
            current.next = null;
            if (current.val % 2 == 0) {
                if (evenHead == null) {
                    evenHead = current;
                    evenTail = current;
                } else {
                    evenTail.next = current;
                    evenTail = current;
                }
            } else {

                if (oddHead == null) {
                    oddHead = current;
                    oddTail = current;
                } else {
                    oddTail.next = current;
                    oddTail = current;
                }
            }
            current = nextNode;
        }
        if (evenHead == null)
            return oddHead;
        evenTail.next = oddHead;
        return evenHead;
    }
}