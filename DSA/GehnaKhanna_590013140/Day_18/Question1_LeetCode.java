class Solution {
    public ListNode rotateRight(ListNode head, int k) {

        if (head == null || head.next == null || k == 0)
            return head;

        // Find length and tail
        int length = 1;
        ListNode tail = head;

        while (tail.next != null) {
            tail = tail.next;
            length++;
        }

        // Reduce k
        k = k % length;

        if (k == 0)
            return head;

        // Make circular
        tail.next = head;

        // Find new tail
        int steps = length - k - 1;
        ListNode newTail = head;

        while (steps-- > 0) {
            newTail = newTail.next;
        }

        // New head
        ListNode newHead = newTail.next;

        // Break circle
        newTail.next = null;

        return newHead;
    }
}
