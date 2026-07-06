class Solution {
    public ListNode deleteDuplicates(ListNode head) {

        ListNode curr = head;

        while (curr != null && curr.next != null) {
            if (curr.val == curr.next.val) {
                curr.next = curr.next.next; // skip the duplicate
            } else {
                curr = curr.next;           // move forward only when no duplicate
            }
        }

        return head;
    }
}
