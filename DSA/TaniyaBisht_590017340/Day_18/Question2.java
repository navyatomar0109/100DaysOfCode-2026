
class ListNode {
    int val; ListNode next;
    ListNode(int val) {
        this.val = val; this.next = null;
    }
}
class DLL{
    public static ListNode removeNthFromEnd(ListNode head, int n) {
        int count = 0;
        ListNode temp = head;
        while (temp != null) {
            count++;
            temp = temp.next;
        }
        if (count == n) {
            return head.next;
        }
        temp = head;
        for (int i = 1; i < count - n; i++) {
            temp = temp.next;
        }
        temp.next = temp.next.next;
        return head;
    }
    public static void printList(ListNode head) {
        while (head != null) {
            System.out.print(head.val);
            if (head.next != null) {
                System.out.print("->");
            }
            head = head.next;
        }
        System.out.println();
    }
    public static void main(String[] args) {
        ListNode n1 = new ListNode(1);
        ListNode n2 = new ListNode(2);
        ListNode n3 = new ListNode(3);
        ListNode n4 = new ListNode(4);
        ListNode n5 = new ListNode(5);
        n1.next = n2;
        n2.next = n3;
        n3.next = n4;
        n4.next = n5;
        int n =3;
        n1 = removeNthFromEnd(n1, n);
        printList(n1);
    }
}