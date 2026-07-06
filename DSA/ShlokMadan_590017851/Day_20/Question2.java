public class Question2 {

    static class ListNode {
        int val;
        ListNode next;

        ListNode(int val) {
            this.val = val;
        }
    }

    public static ListNode segregateEvenOdd(ListNode head) {

        if (head == null) {
            return null;
        }

        ListNode evenHead = null;
        ListNode evenTail = null;
        ListNode oddHead = null;
        ListNode oddTail = null;

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
            oddTail.next = null;
            return oddHead;
        }

        evenTail.next = oddHead;

        if (oddTail != null) {
            oddTail.next = null;
        }

        return evenHead;
    }

    public static void printList(ListNode head) {

        while (head != null) {

            System.out.print(head.val);

            if (head.next != null) {
                System.out.print(" -> ");
            }

            head = head.next;
        }

        System.out.println();
    }

    public static void main(String[] args) {

        ListNode head = new ListNode(17);
        head.next = new ListNode(15);
        head.next.next = new ListNode(8);
        head.next.next.next = new ListNode(9);
        head.next.next.next.next = new ListNode(2);
        head.next.next.next.next.next = new ListNode(4);
        head.next.next.next.next.next.next = new ListNode(6);

        head = segregateEvenOdd(head);

        printList(head);
    }
}