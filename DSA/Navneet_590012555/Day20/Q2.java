Node segregate(Node head) {
    Node eh = null, et = null;
    Node oh = null, ot = null;

    while (head != null) {
        if (head.data % 2 == 0) {
            if (eh == null)
                eh = et = head;
            else {
                et.next = head;
                et = head;
            }
        } else {
            if (oh == null)
                oh = ot = head;
            else {
                ot.next = head;
                ot = head;
            }
        }

        head = head.next;
    }

    if (eh == null)
        return oh;
    if (oh == null)
        return eh;

    et.next = oh;
    ot.next = null;

    return eh;
}