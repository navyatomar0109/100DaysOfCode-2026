public class SegregateNodes {

    //class for creating nodes
    static class ListNode {
        int val;
        ListNode next;

        ListNode(int val) {
            this.val = val;
            this.next = null;
        }
    }

    // Display the linked list
    public static void display(ListNode head) {

        if (head == null) {
            System.out.println("List is empty.");
            return;
        }

        ListNode temp = head;

        while (temp != null) {
            System.out.print(temp.val);

            if (temp.next != null) {
                System.out.print(" -> ");
            }

            temp = temp.next;
        }
        System.out.println();
    }

    // Method for Segregation of even and odd nodes
    public static ListNode Nodes_Segregation(ListNode head) {

        if (head == null) {
            return null;
        }

        ListNode evenHead = null;
        ListNode evenTail = null;

        ListNode oddHead = null;
        ListNode oddTail = null;

        ListNode current = head;

        while (current != null) {

            // Save next node
            ListNode next = current.next;

            // Disconnect current node
            current.next = null;

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

            current = next;
        }

        // No even nodes
        if (evenHead == null) {
            return oddHead;
        }

        // Attach odd list after even list
        evenTail.next = oddHead;

        return evenHead;
    }

    public static void main(String[] args) {

        ListNode head = new ListNode(17);
        head.next = new ListNode(15);
        head.next.next = new ListNode(8);
        head.next.next.next = new ListNode(9);
        head.next.next.next.next = new ListNode(2);
        head.next.next.next.next.next = new ListNode(4);
        head.next.next.next.next.next.next = new ListNode(6);

        System.out.println("Original List:");
        display(head);

        head = Nodes_Segregation(head);

        System.out.println("Modified List:");
        display(head);
    }
}