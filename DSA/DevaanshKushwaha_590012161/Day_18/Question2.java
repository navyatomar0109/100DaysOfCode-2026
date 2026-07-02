class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {

        ListNode dummy = new ListNode(-1);
        dummy.next = head;

        ListNode fast = dummy;
        ListNode slow = dummy;

        // Step 1: Move fast n steps ahead
        for (int i = 0; i < n; i++) {
            fast = fast.next;
        }

        // Step 2: Move both until fast reaches last node
        while (fast.next != null) {
            slow = slow.next;
            fast = fast.next;
        }

        // Step 3: Delete the target node
        slow.next = slow.next.next;

        return dummy.next;
    }
}
