class ListNode {
    int val;
    ListNode next;
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

public class Q2 {

    public ListNode rearrangeEvenOdd(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }

        ListNode evenHead = null, evenTail = null;
        ListNode oddHead = null, oddTail = null;
        
        ListNode current = head;

        while (current != null) {
            if (current.val % 2 == 0) { 
                if (evenHead == null) {
                    evenHead = current;
                    evenTail = current;
                } else {
                    evenTail.next = current;
                    evenTail = current;
                }
            } else { 
                if (oddHead == null) {
                    oddHead = current;
                    oddTail = current;
                } else {
                    oddTail.next = current;
                    oddTail = current;
                }
            }
            current = current.next;
        }

        if (evenHead == null) {
            return oddHead;
        }

        evenTail.next = oddHead;

        if (oddTail != null) {
            oddTail.next = null;
        }

        return evenHead;
    }

    public static void printList(ListNode head) {
        ListNode current = head;
        while (current != null) {
            System.out.print(current.val + (current.next != null ? " -> " : ""));
            current = current.next;
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Q2 obj = new Q2();
        
        ListNode n7 = new ListNode(6);
        ListNode n6 = new ListNode(4, n7);
        ListNode n5 = new ListNode(2, n6);
        ListNode n4 = new ListNode(9, n5);
        ListNode n3 = new ListNode(8, n4);
        ListNode n2 = new ListNode(15, n3);
        ListNode head = new ListNode(17, n2);

        System.out.print("Original list: ");
        printList(head);

        ListNode rearranged = obj.rearrangeEvenOdd(head);

        System.out.print("Rearranged list: ");
        printList(rearranged);
    }
}
