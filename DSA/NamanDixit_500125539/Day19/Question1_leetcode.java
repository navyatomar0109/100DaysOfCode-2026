
class Question1_leetcode {

    public ListNode deleteDuplicates(ListNode head) {

        // If the list is empty
        if (head == null) {
            return null;
        }

        ListNode current = head;

        while (current != null && current.next != null) {

            // If duplicate is found
            if (current.val == current.next.val) {
                current.next = current.next.next;
            } else {
                current = current.next;
            }
        }

        return head;
    }
}
