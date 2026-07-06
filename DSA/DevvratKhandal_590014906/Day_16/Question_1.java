class ListNode {
    int val;
    ListNode next;

    ListNode(int val) {
        this.val = val;
    }
}

public class Question_1 {

    public static ListNode swapPairs(ListNode head) {

        if (head == null || head.next == null) {
            return head;
        }

        ListNode newHead = head.next;
        ListNode prev = null;
        ListNode curr = head;

        while (curr != null && curr.next != null) {

            ListNode second = curr.next;
            ListNode nextPair = second.next;

            second.next = curr;
            curr.next = nextPair;

            if (prev != null) {
                prev.next = second;
            }

            prev = curr;
            curr = nextPair;
        }

        return newHead;
    }

    public static void printList(ListNode head) {
        while (head != null) {
            System.out.print(head.val + " ");
            head = head.next;
        }
    }

    public static void main(String[] args) {

        ListNode head = new ListNode(1);
        head.next = new ListNode(2);
        head.next.next = new ListNode(3);
        head.next.next.next = new ListNode(4);

        System.out.print("Original List: ");
        printList(head);

        head = swapPairs(head);

        System.out.print("\nSwapped List: ");
        printList(head);
    }
}