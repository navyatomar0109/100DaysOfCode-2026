public class Solution {
    public boolean hasCycle(ListNode head) {

        ListNode slow = head;
        ListNode fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;        // 1 step
            fast = fast.next.next;   // 2 steps

            if (slow == fast) {      // met → cycle exists
                return true;
            }
        }

        return false; // fast hit null → no cycle
    }
}
