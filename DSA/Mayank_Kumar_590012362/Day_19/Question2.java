class Solution {
    public ListNode middleNode(ListNode h) {
        ListNode s = h, f = h;
        while (f != null && f.next != null) {
            s = s.next;
            f = f.next.next;
        } return s;
    }
}
