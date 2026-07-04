class Solution {
    public ListNode segregateEvenOdd(ListNode head) {

        if (head == null || head.next == null)
            return head;

        ListNode eH = null, eT = null;
        ListNode oH = null, oT = null;
        ListNode curr = head;
        while (curr != null) {
+
            ListNode next = curr.next;
            curr.next = null;
            if (curr.val % 2 == 0) {
                if (eH == null) {
                    eH = eT = curr;
                } else {
                    eT.next = curr;
                    eT = curr;
                }

            } else {

                if (oH == null) {
                    oH = oT = curr;
                } else {
                    oT.next = curr;
                    oT = curr;
                }
            }

            curr = next;
        }

        if (eH == null)
            return oH;

        eT.next = oH;

        return eH;
    }
}