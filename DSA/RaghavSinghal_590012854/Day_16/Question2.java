class ListNode {
    int val;
    ListNode next;
    ListNode prev;
}

public class Question2 {
    public ListNode deleteLastNode(ListNode head) {
        if (head == null || head.next == null)
            return null;

        ListNode cur = head;

        while (cur.next != null) {
            cur = cur.next;
        }

        cur.prev.next = null;

        return head;
    }
}