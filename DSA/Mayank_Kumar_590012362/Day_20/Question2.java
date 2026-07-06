class Question2 {
    public ListNode segregateEvenOdd(ListNode h) {
        ListNode eh = null, et = null;
        ListNode oh = null, ot = null;
        ListNode c = h;
        while (c != null) {
            if (c.val % 2 == 0) {
                if (eh == null) eh = et = c;
                else {
                    et.next = c;
                    et = c;
                }
            } else {
                if (oh == null) oh = ot = c;
                else {
                    ot.next = c;
                    ot = c;
                }
            } c = c.next;
        }
        if (et != null) et.next = oh;
        if (ot != null) ot.next = null;
        return (eh != null) ? eh : oh;
    }
}