class Solution {
    public boolean isPalindrome(ListNode h) {
        if (h == null || h.next == null) return true;
        ListNode s = h, f = h;
        while (f.next != null && f.next.next != null) {
            s = s.next;
            f = f.next.next;
        }
        ListNode p = null, c = s.next;
        while (c != null) {
            ListNode n = c.next;
            c.next = p;
            p = c; c = n;
        }
        while (p != null) {
            if (h.val != p.val) return false;
            h = h.next; p = p.next;
        }
        return true;
    }
}