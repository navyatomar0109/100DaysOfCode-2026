class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null || head.next == null || k == 0) {
            return head;
        }
        int l = 1;
        ListNode tail = head;
        while (tail.next != null) {
            tail = tail.next;
            l++;
        }
        k = k % l;

        if (k == 0) {
            return head;
        }
        tail.next = head;

        int steps = l - k;
        ListNode newTail = tail;

        while (steps > 0) {
            newTail = newTail.next;
            steps--;
        }

        ListNode newHead = newTail.next;
        newTail.next = null;

        return newHead;
    }
}