class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Q2 {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode fast = dummy;
        ListNode slow = dummy;

        for (int i = 0; i <= n; i++) {
            fast = fast.next;
        }

        while (fast != null) {
            fast = fast.next;
            slow = slow.next;
        }

        slow.next = slow.next.next;
        return dummy.next;
    }

    public static void main(String[] args) {
        ListNode list = new ListNode(1,new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5,null)))));

        Q2 obj = new Q2();
        
        int n = 2;
        ListNode updatedHead = obj.removeNthFromEnd(list, n);
        
        System.out.print("List after removing the node" + n + " node before end: ");
        ListNode currentNode = updatedHead;
        while (currentNode != null) {
            System.out.print(currentNode.val + (currentNode.next != null ? " -> " : ""));
            currentNode = currentNode.next;
        }
        System.out.println();
    }
}