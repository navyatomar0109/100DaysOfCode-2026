public class Solution {

    public boolean Cycle(ListNode head) {
        if (head == null || head.next == null) {
            return false;
        }
        ListNode one = head;
        ListNode two = head;
        while (two != null && two.next != null) {
            one = one.next;
            two = two.next.next;
            if (one == two) {
                return true;
            }
        }
        return false;
    }
}