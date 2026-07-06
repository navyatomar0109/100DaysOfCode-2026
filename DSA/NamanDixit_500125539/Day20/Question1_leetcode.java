
class Question1_leetcode {

    public ListNode removeElements(ListNode head, int val) {

        // Dummy node before head
        ListNode dummy = new ListNode(0);
        dummy.next = head;

        ListNode current = dummy;

        // Traverse the list
        while (current.next != null) {

            // If value matches, remove the node
            if (current.next.val == val) {
                current.next = current.next.next;
            } // Otherwise move ahead
            else {
                current = current.next;
            }
        }

        return dummy.next;
    }
}
