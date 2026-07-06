class Solution {
    public ListNode removeElements(ListNode h, int x) {
        ListNode d = new ListNode(0);
        d.next = h;
        ListNode c = d;
        while (c.next != null) {
            if (c.next.val == x) c.next = c.next.next;
            else c = c.next;
        } return d.next;
    }
}