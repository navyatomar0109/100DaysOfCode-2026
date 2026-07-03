class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

public class Q2 {
    public ListNode findMiddleNode(ListNode head) {
        
        if (head == null) {
            return null;
        }

        ListNode slow = head;
        ListNode fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        return slow;
    }

    public static void main(String[] args) {
        
        ListNode list = new ListNode(1,new ListNode(4, new ListNode(3,new ListNode(2))));

        Q2 obj = new Q2();

        System.out.println(obj.findMiddleNode(list).val);
    }
}
