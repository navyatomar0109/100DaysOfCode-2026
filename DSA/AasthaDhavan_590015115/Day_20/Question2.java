class Question2 {
    public ListNode segregateEvenOdd(ListNode head) {
        if (head == null) return null;

        ListNode evenHead = null, evenTail = null;
        ListNode oddHead = null, oddTail = null;
        ListNode temp = head;

        while (temp != null) {
            if (temp.val % 2 == 0) {
                if (evenHead == null) {
                    evenHead = temp;
                    evenTail = temp;
                } else {
                    evenTail.next = temp;
                    evenTail = temp;
                }
            } else {
                if (oddHead == null) {
                    oddHead = temp;
                    oddTail = temp;
                } else {
                    oddTail.next = temp;
                    oddTail = temp;
                }
            }
            temp = temp.next;
        }

        if (evenHead == null) return oddHead;
        if (oddHead == null) return evenHead;

        evenTail.next = oddHead;
        oddTail.next = null;

        return evenHead;
    }
}